/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** free_data
*/

#include "wolf3d.h"

void free_key(void *data)
{
    item_key_t *key = NULL;

    if (!data)
        return;
    key = (item_key_t *)data;
    free(key);
}

void free_flashlight(void *data)
{
    flashlight_t *flashlight = NULL;

    if (!data)
        return;
    flashlight = (flashlight_t *)data;
    if (flashlight->sheet)
        sfTexture_destroy(flashlight->sheet);
    if (flashlight->flashlight_ss->sprite)
        sfSprite_destroy(flashlight->flashlight_ss->sprite);
    if (flashlight->flashlight_ss->int_rect)
        free(flashlight->flashlight_ss->int_rect);
    if (flashlight->flashlight_ss)
        free(flashlight->flashlight_ss);
    free(flashlight);
}

void free_gun(void *data)
{
    gun_t *gun = NULL;

    if (!data)
        return;
    gun = (gun_t *)data;
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
    void (*free_item[])(void *) =
        {NULL, free_key, free_flashlight, free_gun};

    if (data && type >= 0 && type < ITEM_TYPE_COUNT &&
            free_item[type] != NULL)
        free_item[type](data);
}
