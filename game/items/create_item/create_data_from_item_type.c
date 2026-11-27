/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** create_data_from_item_type
*/

#include "wolf3d.h"

void *create_data_from_item_type(int type)
{
    void *(*create_item[ITEM_TYPE_COUNT])(void) =
        {NULL, create_key, create_flashlight, create_gun};

    if (type >= 0 && type < ITEM_TYPE_COUNT && create_item[type] != NULL)
        return create_item[type]();
    return NULL;
}
