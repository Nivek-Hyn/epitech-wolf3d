/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** draw_flashlight_data
*/

#include "wolf3d.h"

void draw_flashlight_data(game_t *game, item_t selected_slot)
{
    flashlight_t *flashlight = (flashlight_t *)selected_slot.data;

    if (flashlight == NULL)
        return;
    draw_flashlight_battery(game, flashlight);
}
