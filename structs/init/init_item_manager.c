/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** init_item_manager
*/

#include "wolf3d.h"

item_manager_t *init_item_manager(void)
{
    item_manager_t *item_manager = malloc(sizeof(item_manager_t));

    if (!item_manager)
        return NULL;
    item_manager->world_item_count = 0;
    for (int i = 0; i < MAX_WORLD_ITEMS; i++) {
        reset_world_item(&item_manager->world_items[i]);
    }
    load_item_save_file(ITEM_SAVE_FILE, item_manager);
    return item_manager;
}
