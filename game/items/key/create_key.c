/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** create_key
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
