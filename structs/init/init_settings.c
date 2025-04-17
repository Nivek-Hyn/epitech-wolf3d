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
    settings->window_mode = 0;
    settings->field_of_view = 70.0;
    return settings;
}
