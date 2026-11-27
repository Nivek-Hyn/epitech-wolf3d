/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** pickup_item
*/

#include "wolf3d.h"

bool pickup_item(player_t *player, item_manager_t *manager, int index)
{
    if (player->inventory->slots[player->inventory->selected_slot]
            .type == ITEM_NONE) {
        player->inventory->slots[player->inventory->selected_slot] =
            manager->world_items[index].item;
        despawn_item(manager, index);
        return true;
    }
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        if (player->inventory->slots[i].type == ITEM_NONE) {
            player->inventory->slots[i] = manager->world_items[index].item;
            despawn_item(manager, index);
            return true;
        }
    }
    return false;
}
