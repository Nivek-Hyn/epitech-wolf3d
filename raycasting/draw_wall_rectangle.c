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

static void flashlight_manager(game_t *game, raycast_values_t *var,
    float *brightness_factor, float base_brightness)
{
    float flashlight_center = game->settings->ray_count / 2.0f;
    float distance_from_center = (var->drawn_rays - flashlight_center);
    float inner_radius = FLASHLIGHT_RADIUS * 0.3f;
    float outer_radius = FLASHLIGHT_RADIUS;
    float fade_factor = 0.0f;

    if (distance_from_center < 0)
        distance_from_center = -distance_from_center;
    if (distance_from_center <= inner_radius) {
        *brightness_factor = 1.0f;
    } else if (distance_from_center <= outer_radius) {
        fade_factor = (outer_radius - distance_from_center) /
            (outer_radius - inner_radius);
        fade_factor = fade_factor * fade_factor;
        *brightness_factor = base_brightness +
            (1.0f - base_brightness) * fade_factor;
    }
}

void set_sprite_color(sfSprite *sprite, float distance,
    game_t *game, raycast_values_t *var)
{
    float max_dist = 600.0f;
    float base_brightness = WALL_BRIGHTNESS;
    float factor = 1.0f - (distance / max_dist);
    sfColor color;
    float brightness_factor = base_brightness;
    flashlight_t *flashlight = get_flashlight(game->player->inventory);

    if (factor < 0.2f)
        factor = 0.2f;
    if (factor > 1.0f)
        factor = 1.0f;
    if (flashlight && flashlight->is_on)
        flashlight_manager(game, var, &brightness_factor, base_brightness);
    color = sfColor_fromRGB(
        255 * factor * brightness_factor,
        255 * factor * brightness_factor,
        255 * factor * brightness_factor);
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
    sfTexture *texture =
        game->world->wall_textures[game->world->map[map_y][map_x].wall_type];
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    set_texture_rect(sprite, texture, hit, is_vertical);
    set_sprite_position(sprite, var, line_offset, game->settings->ray_count);
    set_sprite_color(sprite, var->total_dist, game, var);
    set_sprite_scale(sprite, texture, line_height, game->settings->ray_count);
    sfRenderWindow_drawSprite(game->render_window, sprite, NULL);
    sfSprite_destroy(sprite);
}
