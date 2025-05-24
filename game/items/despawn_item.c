/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** despawn_item
*/

#include "wolf3d.h"

void despawn_item(item_manager_t *manager, int index)
{
    if (index < 0 || index >= MAX_WORLD_ITEMS)
        return;
    if (manager->world_items[index].sprite)
        sfSprite_destroy(manager->world_items[index].sprite);
    reset_world_item(&manager->world_items[index]);
    manager->world_item_count--;
}
