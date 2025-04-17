/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** init_keys
*/

#include "wolf3d.h"

keys_t *init_keys(void)
{
    keys_t *keys = malloc(sizeof(keys_t));

    if (!keys)
        return NULL;
    keys->z = 0;
    keys->s = 0;
    keys->q = 0;
    keys->d = 0;
    keys->a = 0;
    keys->e = 0;
    return keys;
}
