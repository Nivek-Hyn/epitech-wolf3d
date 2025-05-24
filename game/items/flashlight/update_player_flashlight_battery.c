/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** update_player_flashlight_battery
*/

#include "wolf3d.h"

void update_player_flashlight_battery(game_t *game)
{
    if (game->player->flashlight == true) {
        game->player->flashlight_battery -=
            game->time->delta_time * FLASHLIGHT_BATTERY_DECREASE;
        if (game->player->flashlight_battery <= 0) {
            game->player->flashlight = false;
            game->player->flashlight_battery = 0;
        }
    }
}
