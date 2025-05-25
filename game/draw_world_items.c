/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** draw_world_item
*/

#include "wolf3d.h"

static int compute_angles_and_distance(game_t *game,
    world_item_draw_vars_t *vars, world_item_t *world_item)
{
    player_t *pl = game->player;

    vars->pos = world_item->position;
    vars->dx = vars->pos.x - pl->x;
    vars->dy = vars->pos.y - pl->y;
    vars->distance = sqrtf(vars->dx * vars->dx + vars->dy * vars->dy);
    vars->angle_to_sprite = atan2f(vars->dy, vars->dx);
    vars->relative_angle = vars->angle_to_sprite - pl->angle;
    if (vars->relative_angle < - PI)
        vars->relative_angle += 2 * PI;
    if (vars->relative_angle > PI)
        vars->relative_angle -= 2 * PI;
    if (fabsf(vars->relative_angle) > (PI / 6))
        return 0;
    vars->proj_plane_dist = (RAYCAST_WIN_WITDH / 2.0f) / tanf(PI / 6);
    vars->sprite_screen_x = tanf(vars->relative_angle) * vars->proj_plane_dist;
    vars->screen_x = (int)(RAYCAST_WIN_WITDH / 2 + vars->sprite_screen_x);
    if (vars->screen_x < 0 || vars->screen_x >= RAYCAST_WIN_WITDH)
        return 0;
    return 1;
}

static void update_visible_columns(world_item_draw_vars_t *vars, int x)
{
    if (vars->first_visible_col == -1)
        vars->first_visible_col = x;
    vars->last_visible_col = x;
}

static int find_visible_columns(
    world_item_draw_vars_t *vars, float *ray_distances)
{
    vars->first_visible_col = -1;
    vars->last_visible_col = -1;
    for (int x = vars->visible_start; x <= vars->visible_end; x++) {
        if (vars->distance < ray_distances[x]) {
            update_visible_columns(vars, x);
        }
    }
    return vars->first_visible_col != -1 && vars->last_visible_col != -1;
}

static void limit_visible_bounds(world_item_draw_vars_t *vars)
{
    if (vars->visible_start < 0)
        vars->visible_start = 0;
    if (vars->visible_end >= RAYCAST_WIN_WITDH)
        vars->visible_end = RAYCAST_WIN_WITDH - 1;
}

static int compute_sprite_draw_params(
    game_t *game, world_item_draw_vars_t *vars)
{
    extra_data_t *ex = game->extra_data;

    vars->sprite_screen_size = (int)(WORLD_ITEM_DRAW_SIZE *
        vars->proj_plane_dist / vars->distance);
    if (vars->sprite_screen_size > WORLD_ITEM_MAX_DRAW_SIZE)
        vars->sprite_screen_size = WORLD_ITEM_MAX_DRAW_SIZE;
    vars->draw_start_x = vars->screen_x - vars->sprite_screen_size / 2;
    vars->draw_end_x = vars->screen_x + vars->sprite_screen_size / 2;
    vars->visible_start = vars->draw_start_x;
    vars->visible_end = vars->draw_end_x;
    limit_visible_bounds(vars);
    if (!find_visible_columns(vars, ex->ray_distances))
        return 0;
    return 1;
}

static void set_sprite_texture_and_rect(
    world_item_t *world_item, world_item_draw_vars_t *vars)
{
    vars->tex_size = sfTexture_getSize(world_item->item.texture);
    vars->tex_x_start = (vars->first_visible_col - vars->draw_start_x) *
        vars->tex_size.x / vars->sprite_screen_size;
    vars->tex_x_end = (vars->last_visible_col - vars->draw_start_x) *
        vars->tex_size.x / vars->sprite_screen_size;
    vars->tex_width = vars->tex_x_end - vars->tex_x_start;
    world_item->sprite_rect.left = vars->tex_x_start;
    world_item->sprite_rect.top = 0;
    world_item->sprite_rect.width = vars->tex_width;
    world_item->sprite_rect.height = (int)vars->tex_size.y;
    sfSprite_setTexture(world_item->sprite, world_item->item.texture, sfTrue);
    sfSprite_setTextureRect(world_item->sprite, world_item->sprite_rect);
}

static void set_sprite_scale_and_position(
    world_item_t *world_item, world_item_draw_vars_t *vars)
{
    sfVector2f pos = {
        RAY_OFFSET_X + (float)vars->first_visible_col,
        RAY_OFFSET_Y + (RAYCAST_WIN_HEIGHT - vars->sprite_screen_size) / 2.0f
    };

    vars->scale = (float)vars->sprite_screen_size / vars->tex_size.y;
    sfSprite_setScale(world_item->sprite,
        (sfVector2f){vars->scale, vars->scale});
    sfSprite_setPosition(world_item->sprite, pos);
}

static void set_sprite_color_by_distance(
    world_item_t *world_item, world_item_draw_vars_t *vars)
{
    float max_distance = 250.0f;

    vars->factor = vars->distance / max_distance;
    if (vars->factor > 1.0f)
        vars->factor = 1.0f;
    vars->alpha = (sfUint8)(255 * (1.0f - vars->factor * 0.7f));
    vars->shade = (sfUint8)(255 * (1.0f - vars->factor * 0.5f));
    vars->color = sfColor_fromRGBA(
        vars->shade, vars->shade, vars->shade, vars->alpha);
    sfSprite_setColor(world_item->sprite, vars->color);
}

void draw_world_items(game_t *game)
{
    world_item_draw_vars_t vars;
    item_manager_t *im = game->item_manager;
    world_item_t *world_item = NULL;

    for (int i = 0; i < MAX_WORLD_ITEMS; i++) {
        if (im->world_items[i].item.type == ITEM_NONE)
            continue;
        world_item = &im->world_items[i];
        if (!compute_angles_and_distance(game, &vars, world_item))
            continue;
        if (!compute_sprite_draw_params(game, &vars))
            continue;
        set_sprite_texture_and_rect(world_item, &vars);
        set_sprite_scale_and_position(world_item, &vars);
        set_sprite_color_by_distance(world_item, &vars);
        sfRenderWindow_drawSprite(game->render_window,
            world_item->sprite, NULL);
    }
}
