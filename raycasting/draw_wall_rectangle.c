/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** draw_wall_rectangle
*/

#include "wolf3d.h"

void set_sprite_scale(sfSprite *sprite, sfTexture *texture,
    float line_height, int ray_count)
{
    float ray_spacing = (float)RAYCAST_WIN_WITDH / ray_count;
    sfVector2u tex_dim = sfTexture_getSize(texture);
    sfVector2f scale = {
        ray_spacing / 1.0f,
        line_height / (float)tex_dim.y
    };

    sfSprite_setScale(sprite, scale);
}

void set_sprite_color(sfSprite *sprite, float distance)
{
    float max_dist = 600.0f;
    float factor = 1.0f - (distance / max_dist);
    sfColor color;

    if (factor < 0.2f)
        factor = 0.2f;
    if (factor > 1.0f)
        factor = 1.0f;
    color = sfColor_fromRGB(
        255 * factor, 255 * factor, 255 * factor);
    sfSprite_setColor(sprite, color);
}

void set_sprite_position(sfSprite *sprite, raycast_values_t *var,
    float line_offset, int ray_count)
{
    float ray_spacing = (float)RAYCAST_WIN_WITDH / ray_count;
    sfVector2f position = {
        RAY_OFFSET_X + var->drawn_rays * ray_spacing,
        RAY_OFFSET_Y + line_offset
    };

    sfSprite_setPosition(sprite, position);
}

void set_texture_rect(sfSprite *sprite, sfTexture *texture,
    sfVector2f hit, int is_vertical)
{
    float offset = is_vertical ?
        fmod(hit.y, TILE_SIZE) : fmod(hit.x, TILE_SIZE);
    sfVector2u tex_dim = sfTexture_getSize(texture);
    int tex_x = (offset / TILE_SIZE) * tex_dim.x;
    sfIntRect texture_rect = {tex_x, 0, 1, (int)tex_dim.y};

    sfSprite_setTextureRect(sprite, texture_rect);
}

void draw_wall_rectangle(game_t *game, raycast_values_t *var,
    float line_height, float line_offset)
{
    int is_vertical = (var->vertical_dist < var->horizontal_dist);
    sfVector2f hit = {
        is_vertical ? var->vertical_x : var->horizontal_x,
        is_vertical ? var->vertical_y : var->horizontal_y
    };
    int map_x = (int)(hit.x / TILE_SIZE);
    int map_y = (int)(hit.y / TILE_SIZE);
    sfTexture *texture = game->world->map[map_y][map_x].texture;
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    set_texture_rect(sprite, texture, hit, is_vertical);
    set_sprite_position(sprite, var, line_offset, game->settings->ray_count);
    set_sprite_color(sprite, var->total_dist);
    set_sprite_scale(sprite, texture, line_height, game->settings->ray_count);
    sfRenderWindow_drawSprite(game->render_window, sprite, NULL);
    sfSprite_destroy(sprite);
}
