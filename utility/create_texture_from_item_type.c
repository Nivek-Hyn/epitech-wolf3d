/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** create_texture_from_item_type
*/

#include "wolf3d.h"

sfTexture *create_texture_from_item_type(int type)
{
    switch (type) {
        case ITEM_FLASHLIGHT:
            return sfTexture_createFromFile(
                "assets/textures/items/flashlight.png", NULL);
        default:
            return NULL;
    }
}
