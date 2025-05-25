/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** use_selected_item
*/

#include "wolf3d.h"

void use_key(game_t *game, inventory_t *inventory)
{
    return;
}

void use_gun(game_t *game, inventory_t *inventory)
{
    return;
}

void use_selected_item(game_t *game, inventory_t *inventory)
{
    switch (inventory->slots[inventory->selected_slot].type) {
        case ITEM_KEY:
            use_key(game, inventory);
            break;
        case ITEM_FLASHLIGHT:
            turn_flashlight(game);
            break;
        case ITEM_GUN:
            use_gun(game, inventory);
            break;
    }
}
