/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** horizontal_raycast
*/

#include "wolf3d.h"

void horizontal_ray_down(game_t *game, raycast_values_t *var, float atan)
{
    if (var->ray_angle > PI) {
        var->ray_y = (((int)game->player->y / TILE_SIZE) * TILE_SIZE) - 0.0001;
        var->ray_x = (game->player->y - var->ray_y) * atan + game->player->x;
        var->y_offset = -TILE_SIZE;
        var->x_offset = -var->y_offset * atan;
    }
}

void horizontal_ray_up(game_t *game, raycast_values_t *var, float atan)
{
    if (var->ray_angle < PI) {
        var->ray_y = (((int)game->player->y / TILE_SIZE) * TILE_SIZE)
            + TILE_SIZE;
        var->ray_x = (game->player->y - var->ray_y) * atan + game->player->x;
        var->y_offset = TILE_SIZE;
        var->x_offset = -var->y_offset * atan;
    }
}

void horizontal_ray_straight(game_t *game, raycast_values_t *var)
{
    if (var->ray_angle == 0 || var->ray_angle == PI) {
        var->ray_x = game->player->x;
        var->ray_y = game->player->y;
        var->depth_of_field = STD_DOF;
    }
}

void horizontal_ray_extend(game_t *game, raycast_values_t *var)
{
    var->map_x = ((int)var->ray_x / TILE_SIZE);
    var->map_y = ((int)var->ray_y / TILE_SIZE);
    if (var->map_x < game->world->map_size_x && var->map_x >= 0 &&
            var->map_y < game->world->map_size_y && var->map_y >= 0 &&
            game->world->map[var->map_y][var->map_x].type == WALL) {
        var->horizontal_x = var->ray_x;
        var->horizontal_y = var->ray_y;
        var->horizontal_dist = player_to_ray_distance(game->player,
            var->horizontal_x, var->horizontal_y, var->ray_angle);
        var->depth_of_field = STD_DOF - 1;
    } else {
        var->ray_x += var->x_offset;
        var->ray_y += var->y_offset;
    }
}

void horizontal_raycast(game_t *game, raycast_values_t *var)
{
    float atan = -1 / tan(var->ray_angle);

    var->horizontal_dist = 1000000;
    var->horizontal_x = game->player->x;
    var->horizontal_y = game->player->y;
    var->depth_of_field = 0;
    horizontal_ray_down(game, var, atan);
    horizontal_ray_up(game, var, atan);
    horizontal_ray_straight(game, var);
    for (; var->depth_of_field < STD_DOF; var->depth_of_field++) {
        horizontal_ray_extend(game, var);
    }
}
