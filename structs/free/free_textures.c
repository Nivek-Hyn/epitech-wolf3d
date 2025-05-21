/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** free_textures
*/

#include "wolf3d.h"

void free_textures(sfTexture **textures)
{
    for (int i = 0; i < NB_TILE_TYPES; i++) {
        if (textures[i]) {
            sfTexture_destroy(textures[i]);
        }
    }
}
