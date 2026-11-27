/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** update_player_flashlight_battery
*/

#include "wolf3d.h"

void update_player_flashlight_battery(game_t *game)
{
    item_t selected_slot = game->player->inventory->
        slots[game->player->inventory->selected_slot];
    flashlight_t *flashlight = NULL;

    if (selected_slot.type == ITEM_FLASHLIGHT && selected_slot.data != NULL)
        flashlight = (flashlight_t *)selected_slot.data;
    if (flashlight && flashlight->is_on == true) {
        flashlight->battery -=
            game->time->delta_time * FLASHLIGHT_BATTERY_DECREASE;
        if (flashlight->battery <= 0) {
            flashlight->is_on = false;
            flashlight->battery = 0;
        }
    }
}
