/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** create_data_from_item_type
*/

#include "wolf3d.h"

void *create_data_from_item_type(int type)
{
    switch (type) {
        case ITEM_KEY:
            return create_key();
        case ITEM_FLASHLIGHT:
            return create_flashlight();
        case ITEM_GUN:
            return create_gun();
        default:
            return NULL;
    }
}
