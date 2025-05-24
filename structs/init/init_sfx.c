/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues [WSL: Ubuntu]
** File description:
** init_sfx
*/

#include "wolf3d.h"

static void init_hover_sfx(sfx_t *sfx, settings_t *settings)
{
    sfx->button_hover_buffer =
        sfSoundBuffer_createFromFile("assets/sfx/button_hover.wav");
    sfx->button_hover = sfSound_create();
    sfSound_setBuffer(sfx->button_hover, sfx->button_hover_buffer);
    sfSound_setVolume(sfx->button_hover, settings->sfx_volume);
}

static void init_click_sfx(sfx_t *sfx, settings_t *settings)
{
    sfx->button_click_buffer =
        sfSoundBuffer_createFromFile("assets/sfx/button_click.wav");
    sfx->button_click = sfSound_create();
    sfSound_setBuffer(sfx->button_click, sfx->button_click_buffer);
    sfSound_setVolume(sfx->button_click, settings->sfx_volume);
}

static void init_button_sfx(sfx_t *sfx, settings_t *settings)
{
    init_hover_sfx(sfx, settings);
    init_click_sfx(sfx, settings);
}

static void init_menu_music(sfx_t *sfx, settings_t *settings)
{
    sfx->menu_music = sfMusic_createFromFile("assets/sfx/AjouraMusic.mp3");
    sfMusic_setLoop(sfx->menu_music, sfTrue);
    sfMusic_setVolume(sfx->menu_music, settings->music_volume);
}

sfx_t *init_sfx(settings_t *settings)
{
    sfx_t *sfx = malloc(sizeof(sfx_t));

    if (sfx == NULL)
        return NULL;
    init_menu_music(sfx, settings);
    init_button_sfx(sfx, settings);
    return sfx;
}
