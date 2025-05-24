/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** inventory_select_next_slot
*/

#include "wolf3d.h"

void inventory_select_next_slot(inventory_t *inventory)
{
    inventory->selected_slot++;
    if (inventory->selected_slot >= INVENTORY_SIZE)
        inventory->selected_slot = 0;
}
