/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues [WSL: Ubuntu]
** File description:
** check_buttons_event
*/

#include "wolf3d.h"

void check_settings_buttons_events(game_t *game)
{
    check_window_change_button_events(game);
    check_return_button_events(game);
}
