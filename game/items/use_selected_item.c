/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** use_selected_item
*/

#include "wolf3d.h"

void use_selected_item(game_t *game, inventory_t *inventory)
{
    item_t *item = inventory_selected_slot(inventory);
    void (*use_item[])(game_t *, inventory_t *) =
        {NULL, use_key, turn_flashlight, use_shoot};

    if (item && item->data &&
            item->type >= 0 && item->type < ITEM_TYPE_COUNT &&
                use_item[item->type] != NULL)
        use_item[item->type](game, inventory);
}
