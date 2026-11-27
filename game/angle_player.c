/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** move_player
*/

#include "wolf3d.h"

void player_look_left(game_t *game, float look_speed)
{
    game->player->angle -= 0.05 * look_speed;
    if (game->player->angle < 0)
        game->player->angle += (2 * PI);
    game->player->delta_x = (cos(game->player->angle));
    game->player->delta_y = (sin(game->player->angle));
}

void player_look_right(game_t *game, float look_speed)
{
    game->player->angle += 0.05 * look_speed;
    if (game->player->angle > (2 * PI))
        game->player->angle -= (2 * PI);
    game->player->delta_x = (cos(game->player->angle));
    game->player->delta_y = (sin(game->player->angle));
}
