/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** init_player
*/

#include "wolf3d.h"

player_t *init_player(void)
{
    player_t *player = malloc(sizeof(player_t));

    player->x = 0;
    player->y = 0;
    player->angle = 0;
    player->delta_x = (cos(player->angle) * 5);
    player->delta_y = (sin(player->angle) * 5);
    player->player_visual = create_circle((sfVector2f){player->x, player->y},
        10, sfWhite, sfGreen);
    return player;
}
