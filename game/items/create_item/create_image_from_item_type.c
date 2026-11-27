/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** create_image_from_item_type
*/

#include "wolf3d.h"

sfImage *create_image_from_item_type(int type)
{
    switch (type) {
        case ITEM_KEY:
            return sfImage_createFromFile(
                "assets/textures/items/key.png");
        case ITEM_FLASHLIGHT:
            return sfImage_createFromFile(
                "assets/textures/items/flashlight.png");
        case ITEM_GUN:
            return sfImage_createFromFile(
                "assets/textures/items/gun.png");
        default:
            return NULL;
    }
}
