/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** init_settings
*/

#include "wolf3d.h"

settings_t *init_settings(void)
{
    settings_t *settings = malloc(sizeof(settings_t));

    if (!settings)
        return NULL;
    settings->window_mode = WINDOWED;
    settings->window_width = STD_WIN_WIDTH;
    settings->window_height = STD_WIN_HEIGHT;
    settings->fov = STD_FOV;
    settings->ray_count = RAYCAST_WIN_WITDH;
    settings->music_volume = MUSIC_VOLUME;
    settings->sfx_volume = SFX_VOLUME;
    settings->sfx_mute = false;
    settings->music_mute = false;
    return settings;
}
