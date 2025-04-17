/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** vertical_raycast
*/

#include "wolf3d.h"

void vertical_ray_right(game_t *game, raycast_values_t *var, float ntan)
{
    if (var->ray_angle < PI2 || var->ray_angle > PI3) {
        var->ray_x = (((int)game->player->x / TILE_SIZE) * TILE_SIZE)
            + TILE_SIZE;
        var->ray_y = (game->player->x - var->ray_x) * ntan + game->player->y;
        var->x_offset = TILE_SIZE;
        var->y_offset = -var->x_offset * ntan;
    }
}

void vertical_ray_left(game_t *game, raycast_values_t *var, float ntan)
{
    if (var->ray_angle > PI2 && var->ray_angle < PI3) {
        var->ray_x = (((int)game->player->x / TILE_SIZE) * TILE_SIZE) - 0.0001;
        var->ray_y = (game->player->x - var->ray_x) * ntan + game->player->y;
        var->x_offset = -TILE_SIZE;
        var->y_offset = -var->x_offset * ntan;
    }
}

void vertical_ray_straight(game_t *game, raycast_values_t *var)
{
    if (var->ray_angle == 0 || var->ray_angle == PI) {
        var->ray_x = game->player->x;
        var->ray_y = game->player->y;
        var->depth_of_field = STD_DOF;
    }
}

void draw_vertical_ray(game_t *game, raycast_values_t *var)
{
    draw_std_line(game->render_window,
        (sfVertex){.position =
            (sfVector2f){game->player->x, game->player->y}, .color = sfWhite},
        (sfVertex){.position =
            (sfVector2f){var->ray_x, var->ray_y}, .color = sfWhite});
}

void vertical_raycast(game_t *game, raycast_values_t *var)
{
    float ntan = -tan(var->ray_angle);

    var->depth_of_field = 0;
    vertical_ray_right(game, var, ntan);
    vertical_ray_left(game, var, ntan);
    vertical_ray_straight(game, var);
    for (; var->depth_of_field < STD_DOF; var->depth_of_field++) {
        var->map_x = ((int)var->ray_x / TILE_SIZE);
        var->map_y = ((int)var->ray_y / TILE_SIZE);
        if (var->map_x < game->world->map_size_x && var->map_x >= 0 &&
                var->map_y < game->world->map_size_y && var->map_y >= 0 &&
                game->world->map[var->map_y][var->map_x].type == WALL) {
            var->depth_of_field = STD_DOF - 1;
        } else {
            var->ray_x += var->x_offset;
            var->ray_y += var->y_offset;
        }
    }
    draw_vertical_ray(game, var);
}
