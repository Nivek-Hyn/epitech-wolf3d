/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** check_mouse_events
*/

#include "wolf3d.h"

void check_mouse_inputs(game_t *game)
{
    if (game->event.type == sfEvtMouseButtonPressed) {
        mouse_button_pressed(game);
    }
    if (game->event.type == sfEvtMouseButtonReleased) {
        mouse_button_released(game);
    }
    if (game->event.type == sfEvtMouseWheelScrolled) {
        mouse_wheel_scrolled(game);
    }
    if (game->event.type == sfEvtMouseMoved) {
        mouse_moved(game);
    }
}
