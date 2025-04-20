/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** raycast
*/

#include "wolf3d.h"

float player_to_ray_distance(player_t *player,
    float ray_x, float ray_y, float angle)
{
    return (sqrt((ray_x - player->x) * (ray_x - player->x) +
        (ray_y - player->y) * (ray_y - player->y)));
}

void set_ray_distance(raycast_values_t *var)
{
    if (var->vertical_dist < var->horizontal_dist) {
        var->ray_x = var->vertical_x;
        var->ray_y = var->vertical_y;
        var->total_dist = var->vertical_dist;
    }
    if (var->horizontal_dist < var->vertical_dist) {
        var->ray_x = var->horizontal_x;
        var->ray_y = var->horizontal_y;
        var->total_dist = var->horizontal_dist;
    }
}

void draw_ray(game_t *game, raycast_values_t *var)
{
    draw_std_line(game->render_window,
        (sfVertex){.position = (sfVector2f)
            {game->player->x, game->player->y}, .color = sfRed},
        (sfVertex){.position = (sfVector2f)
            {var->ray_x, var->ray_y}, .color = sfRed});
}

void set_ray_angle_limit(raycast_values_t *var)
{
    if (var->ray_angle < 0) {
        var->ray_angle += 2 * PI;
    }
    if (var->ray_angle > 2 * PI) {
        var->ray_angle -= 2 * PI;
    }
}

void raycast(game_t *game)
{
    raycast_values_t *var = init_raycast_values();

    var->ray_angle = game->player->angle -
        (RAD_OFFSET * game->settings->fov / 2) * 2;
    set_ray_angle_limit(var);
    for (var->drawn_rays = 0; var->drawn_rays < game->settings->fov * 2;
            var->drawn_rays++) {
        horizontal_raycast(game, var);
        vertical_raycast(game, var);
        set_ray_distance(var);
        draw_ray(game, var);
        draw_3d_walls(game, var);
        var->ray_angle += RAD_OFFSET;
        set_ray_angle_limit(var);
    }
    free_raycast_values(var);
}
