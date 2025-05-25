/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** spawn_item
*/

#include "wolf3d.h"

bool spawn_item(item_manager_t *manager, item_t item, sfVector2f pos)
{
    if (manager->world_item_count >= MAX_WORLD_ITEMS)
        return false;
    for (int i = 0; i < MAX_WORLD_ITEMS; i++) {
        if (manager->world_items[i].item.type == ITEM_NONE) {
            manager->world_items[i].item = item;
            manager->world_items[i].position = pos;
            manager->world_items[i].sprite = sfSprite_create();
            sfSprite_setTexture(manager->world_items[i].sprite,
                item.texture, sfTrue);
            manager->world_items[i].sprite_rect = (sfIntRect){0, 0, 0, 0};
            sfSprite_setPosition(manager->world_items[i].sprite, pos);
            manager->world_items[i].circle_visual =
                create_circle(pos, ITEM_RADIUS, sfTransparent, sfYellow);
            manager->world_item_count++;
            return true;
        }
    }
    return false;
}
