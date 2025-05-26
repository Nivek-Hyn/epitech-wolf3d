/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** create_flashlight
*/

#include "wolf3d.h"

void *create_flashlight(void)
{
    flashlight_t *flashlight = malloc(sizeof(flashlight_t));

    if (!flashlight)
        return NULL;
    flashlight->is_on = false;
    flashlight->battery = 100.0f;
    return (void *)flashlight;
}
