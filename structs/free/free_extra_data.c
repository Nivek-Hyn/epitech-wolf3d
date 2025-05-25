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
    free(extra_data);
}
