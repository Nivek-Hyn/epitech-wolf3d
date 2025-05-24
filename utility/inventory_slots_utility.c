/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** inventory_slots_utility
*/

#include "wolf3d.h"

void *inventory_slot_data(inventory_t *inventory, int slot)
{
    item_t *item = inventory_slot(inventory, slot);

    if (!item && item->data == NULL)
        return NULL;
    return item->data;
}

void *inventory_selected_slot_data(inventory_t *inventory)
{
    return inventory_slot_data(inventory, inventory->selected_slot);
}

item_t *inventory_slot(inventory_t *inventory, int slot)
{
    if (slot < 0 || slot >= INVENTORY_SIZE)
        return NULL;
    return &inventory->slots[slot];
}

item_t *inventory_selected_slot(inventory_t *inventory)
{
    return inventory_slot(inventory, inventory->selected_slot);
}
