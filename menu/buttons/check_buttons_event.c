/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues [WSL: Ubuntu]
** File description:
** check_buttons_event
*/

#include "wolf3d.h"

void check_main_menu_buttons_events(game_t *game)
{
    check_play_button_events(game);
    check_settings_button_events(game);
    check_quit_button_events(game);
}
