/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** get_texture_from_list
*/

#include "wolf3d.h"

sfTexture *get_texture_from_tile_type(tile_t type)
{
    sfTexture *texture = NULL;

    switch (type) {
        case WALL:
            texture =
                sfTexture_createFromFile("assets/backrooms_wall.png", NULL);
            break;
        default:
            texture =
                sfTexture_createFromFile("assets/backrooms_wall.png", NULL);
            break;
    }
    return texture;
}
