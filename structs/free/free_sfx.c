/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues [WSL: Ubuntu]
** File description:
** free_sfx
*/

#include "wolf3d.h"

void free_sfx(sfx_t *sfx)
{
    sfSound_destroy(sfx->button_hover);
    sfSoundBuffer_destroy(sfx->button_hover_buffer);
    sfSound_destroy(sfx->button_click);
    sfSoundBuffer_destroy(sfx->button_click_buffer);
    sfMusic_destroy(sfx->menu_music);
    free(sfx);
}
