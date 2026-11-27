/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** get_flashlight
*/

#include "wolf3d.h"

flashlight_t *get_flashlight(inventory_t *inventory)
{
    item_t *item = inventory_selected_slot(inventory);

    if (item->type != ITEM_FLASHLIGHT || item->data == NULL)
        return NULL;
    return (flashlight_t *)item->data;
}
