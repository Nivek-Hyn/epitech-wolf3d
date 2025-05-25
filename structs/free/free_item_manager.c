/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** free_item_manager
*/

#include "wolf3d.h"

void free_item_manager(item_manager_t *item_manager)
{
    if (item_manager == NULL)
        return;
    for (int i = 0; i < MAX_WORLD_ITEMS; i++) {
        if (item_manager->world_items[i].sprite)
            sfSprite_destroy(item_manager->world_items[i].sprite);
        if (item_manager->world_items[i].circle_visual)
            sfCircleShape_destroy(item_manager->world_items[i].circle_visual);
        if (item_manager->world_items[i].item.texture)
            sfTexture_destroy(item_manager->world_items[i].item.texture);
        if (item_manager->world_items[i].item.image)
            sfImage_destroy(item_manager->world_items[i].item.image);
        if (item_manager->world_items[i].item.data)
            free(item_manager->world_items[i].item.data);
        reset_world_item(&item_manager->world_items[i]);
    }
    free(item_manager);
}
