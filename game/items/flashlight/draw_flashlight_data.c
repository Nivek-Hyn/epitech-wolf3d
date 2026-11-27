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
    sfIntRect rect = flashlight->flashlight_ss->int_rect[flashlight->is_on];
    sfVector2f pos = {
        RAYCAST_WIN_X_CENTER - rect.width / 2.0f,
        RAYCAST_WIN_HEIGHT - rect.height
    };

    if (flashlight == NULL)
        return;
    draw_flashlight_battery(game, flashlight);
    sfSprite_setPosition(flashlight->flashlight_ss->sprite, pos);
    sfRenderWindow_drawSprite(game->render_window,
        flashlight->flashlight_ss->sprite, NULL);
}
