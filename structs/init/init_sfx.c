/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues [WSL: Ubuntu]
** File description:
** init_sfx
*/

#include "wolf3d.h"

static void init_menu_music(sfx_t *sfx, settings_t *settings)
{
    sfx->menu_music = sfMusic_createFromFile("assets/sfx/AjouraMusic.mp3");
    sfMusic_setLoop(sfx->menu_music, sfTrue);
    sfMusic_setVolume(sfx->menu_music, settings->music_volume);
}

sfx_t *init_sfx(settings_t *settings)
{
    sfx_t *sfx = malloc(sizeof(sfx_t));

    if (!sfx)
        return NULL;
    init_menu_music(sfx, settings);
    return sfx;
}
