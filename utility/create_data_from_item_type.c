/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** create_data_from_item_type
*/

#include "wolf3d.h"

void *create_key(void)
{
    item_key_t *key = malloc(sizeof(item_key_t));

    if (!key)
        return NULL;
    key->id = 1;
    return (void *)key;
}

void *create_gun(void)
{
    gun_t *gun = malloc(sizeof(gun_t));

    if (!gun)
        return NULL;
    gun->ammo = 10;
    return (void *)gun;
}

void *create_flashlight(void)
{
    flashlight_t *flashlight = malloc(sizeof(flashlight_t));

    if (!flashlight)
        return NULL;
    flashlight->is_on = false;
    flashlight->battery = 100.0f;
    return (void *)flashlight;
}

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
