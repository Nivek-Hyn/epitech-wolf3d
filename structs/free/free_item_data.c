/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** free_data
*/

#include "wolf3d.h"

void free_key(item_key_t *key)
{
    free(key);
}

void free_flashlight(flashlight_t *flashlight)
{
    free(flashlight);
}

void free_gun(gun_t *gun)
{
    if (gun->sheet)
        sfTexture_destroy(gun->sheet);
    if (gun->gun_ss->sprite)
        sfSprite_destroy(gun->gun_ss->sprite);
    if (gun->gun_ss->int_rect)
        free(gun->gun_ss->int_rect);
    if (gun->gun_ss)
        free(gun->gun_ss);
    free(gun);
}

void free_item_data(void *data, item_type_t type)
{
    if (!data)
        return;
    switch (type) {
        case ITEM_KEY:
            free_key((item_key_t *)data);
            break;
        case ITEM_FLASHLIGHT:
            free_flashlight((flashlight_t *)data);
            break;
        case ITEM_GUN:
            free_gun((gun_t *)data);
            break;
    }
}
