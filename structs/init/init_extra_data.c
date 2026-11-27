/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** init_extra_data
*/

#include "wolf3d.h"

extra_data_t *init_extra_data(void)
{
    extra_data_t *extra_data = malloc(sizeof(extra_data_t));

    if (!extra_data)
        return NULL;
    for (int i = 0; i < RAYCAST_WIN_WITDH; i++)
        extra_data->ray_distances[i] = 0.0f;
    extra_data->textures = NULL;
    extra_data->nb_textures = 0;
    return extra_data;
}
