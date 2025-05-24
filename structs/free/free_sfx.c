/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues [WSL: Ubuntu]
** File description:
** free_sfx
*/

#include "wolf3d.h"

void free_sfx(sfx_t *sfx)
{
    if (sfx->menu_music != NULL) {
        sfMusic_destroy(sfx->menu_music);
    }
    free(sfx);
}
