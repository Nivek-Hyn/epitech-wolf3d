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
    if (flashlight)
        flashlight->is_on = !flashlight->is_on;
}
