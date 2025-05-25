/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues [WSL: Ubuntu]
** File description:
** settings_menu_loop
*/

#include "wolf3d.h"

static void draw_settings_menu_stuff(game_t *game)
{
    sfRenderWindow_drawSprite(
        game->render_window,
        game->sprites->WindowMode_text,
        NULL
    );
}

void settings_menu_render(game_t *game)
{
    draw_main_menu_background(game);
    draw_settings_menu_stuff(game);
    draw_settings_buttons(game);
}

void settings_menu_loop(game_t *game)
{
    check_events(game);
    check_settings_buttons_events(game);
    settings_menu_render(game);
}
