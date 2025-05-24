/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** reset_inventory_slot
*/

#include "wolf3d.h"

void reset_inventory_slot(inventory_t *inventory, int slot_index)
{
    if (slot_index < 0 || slot_index >= INVENTORY_SIZE)
        return;
    inventory->slots[slot_index].type = ITEM_NONE;
    inventory->slots[slot_index].quantity = 0;
    inventory->slots[slot_index].texture = NULL;
    inventory->slots[slot_index].data = NULL;
}
