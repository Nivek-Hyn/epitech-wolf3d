/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** create_item
*/

#include "wolf3d.h"

item_t create_item(int type)
{
    item_t item;

    item.type = type;
    item.quantity = 1;
    item.texture = create_texture_from_item_type(type);
    item.image = create_image_from_item_type(type);
    item.data = create_data_from_item_type(type);
    return item;
}
