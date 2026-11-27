/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues [WSL: Ubuntu]
** File description:
** free_sfx
*/

#include "wolf3d.h"

static void free_more_sfx(sfx_t *sfx)
{
    sfSound_destroy(sfx->footstep);
    sfSoundBuffer_destroy(sfx->footstep_buffer);
    sfSound_destroy(sfx->footstep_two);
    sfSoundBuffer_destroy(sfx->footstep_two_buffer);
    sfSound_destroy(sfx->footstep_three);
    sfSoundBuffer_destroy(sfx->footstep_three_buffer);
    sfSound_destroy(sfx->footstep_four);
    sfSoundBuffer_destroy(sfx->footstep_four_buffer);
    sfMusic_stop(sfx->menu_music);
    sfMusic_destroy(sfx->menu_music);
}

void free_sfx(sfx_t *sfx)
{
    sfSound_destroy(sfx->button_hover);
    sfSoundBuffer_destroy(sfx->button_hover_buffer);
    sfSound_destroy(sfx->button_click);
    sfSoundBuffer_destroy(sfx->button_click_buffer);
    sfSound_destroy(sfx->gunshot);
    sfSoundBuffer_destroy(sfx->gunshot_buffer);
    sfSound_destroy(sfx->empty_gun);
    sfSoundBuffer_destroy(sfx->empty_gun_buffer);
    sfSound_destroy(sfx->flashlight_toggle);
    sfSoundBuffer_destroy(sfx->flashlight_toggle_buffer);
    sfSound_destroy(sfx->flashlight_battery_depleted);
    sfSoundBuffer_destroy(sfx->flashlight_battery_depleted_buffer);
    free_more_sfx(sfx);
    free(sfx);
}
