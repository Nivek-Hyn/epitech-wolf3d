/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** drop_inventory_item
*/

#include "wolf3d.h"

bool drop_inventory_item(player_t *player, item_manager_t *manager, int slot)
{
    sfVector2f drop_pos;

    if (player->inventory->slots[slot].type == ITEM_NONE)
        return false;
    drop_pos = (sfVector2f){player->x + cosf(player->angle) * 20,
        player->y + sinf(player->angle) * 20};
    if (spawn_item(manager,
            player->inventory->slots[slot], drop_pos) == true)
        reset_inventory_slot(player->inventory, slot);
    return true;
}
