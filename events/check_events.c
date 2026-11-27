/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** check_events
*/

#include "wolf3d.h"

void check_events(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->render_window,
            &game->event) != sfFalse) {
        check_window_events(game);
        check_keyboard_inputs(game);
        check_mouse_inputs(game);
    }
}
