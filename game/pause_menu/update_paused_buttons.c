/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues [WSL: Ubuntu]
** File description:
** update_paused_buttons
*/

#include "wolf3d.h"

void update_paused_buttons(game_t *game)
{
    check_paused_settings_button_events(game);
    check_paused_menu_button_events(game);
    check_paused_save_button_events(game);
    check_paused_load_button_events(game);
}
