/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** stock_texture_in_extra_data
*/

#include "wolf3d.h"

void stock_texture_in_extra_data(sfTexture *texture,
    extra_data_t *extra_data)
{
    if (!texture || !extra_data)
        return;
    extra_data->textures = realloc(extra_data->textures,
        sizeof(sfTexture *) * (extra_data->nb_textures + 1));
    if (!extra_data->textures)
        return;
    extra_data->textures[extra_data->nb_textures] = texture;
    extra_data->nb_textures++;
}
