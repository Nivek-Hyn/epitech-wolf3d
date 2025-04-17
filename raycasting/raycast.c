/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** raycast
*/

#include "wolf3d.h"

void raycast(game_t *game)
{
    raycast_values_t *var = init_raycast_values();

    var->ray_angle = game->player->angle;
    for (var->r = 0; var->r < 1; var->r++) {
        horizontal_raycast(game, var);
        vertical_raycast(game, var);
    }
    free_raycast_values(var);
}
