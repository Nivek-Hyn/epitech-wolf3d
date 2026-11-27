/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** turn_flashlight
*/

#include "wolf3d.h"

void turn_flashlight(game_t *game, inventory_t *inventory)
{
    item_t *selected_slot = inventory_selected_slot(inventory);
    flashlight_t *flashlight = NULL;

    if (selected_slot->type == ITEM_FLASHLIGHT && selected_slot->data != NULL)
        flashlight = (flashlight_t *)selected_slot->data;
    if (flashlight) {
        if (flashlight->battery <= 0 && game->current_scene == GAME) {
            sfSound_play(game->sounds->flashlight_battery_depleted);
            sfSprite_setTextureRect(flashlight->flashlight_ss->sprite,
                flashlight->flashlight_ss->int_rect[0]);
        }
        if (flashlight->battery > 0 && game->current_scene == GAME) {
            sfSound_play(game->sounds->flashlight_toggle);
            sfSprite_setTextureRect(flashlight->flashlight_ss->sprite,
                flashlight->flashlight_ss->int_rect[!flashlight->is_on]);
        }
        flashlight->is_on = !flashlight->is_on;
    }
}
