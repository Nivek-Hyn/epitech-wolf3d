/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** reset_world_item
*/

#include "wolf3d.h"

void reset_world_item(world_item_t *item)
{
    item->item.type = ITEM_NONE;
    item->item.quantity = 0;
    item->item.texture = NULL;
    item->item.data = NULL;
    item->position = (sfVector2f){0, 0};
    item->sprite = NULL;
    item->circle_visual = NULL;
}
