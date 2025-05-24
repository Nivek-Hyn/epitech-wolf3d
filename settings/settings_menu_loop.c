/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues [WSL: Ubuntu]
** File description:
** settings_menu_loop
*/

#include "wolf3d.h"

void settings_menu_render(game_t *game)
{
    draw_main_menu_background(game);
}

void settings_menu_loop(game_t *game)
{
    check_events(game);
    settings_menu_render(game);
}
