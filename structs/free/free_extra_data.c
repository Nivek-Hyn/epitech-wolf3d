/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** free_extra_data
*/

#include "wolf3d.h"

void free_extra_data(extra_data_t *extra_data)
{
    if (extra_data == NULL)
        return;
    for (int i = 0; i < extra_data->nb_textures; i++) {
        if (extra_data->textures[i])
            sfTexture_destroy(extra_data->textures[i]);
    }
    if (extra_data->textures)
        free(extra_data->textures);
    if (extra_data->step_clock)
        sfClock_destroy(extra_data->step_clock);
    free(extra_data);
}
