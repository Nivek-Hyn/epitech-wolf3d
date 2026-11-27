/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues [WSL: Ubuntu]
** File description:
** draw_buttons
*/

#include "wolf3d.h"

static void draw_play_button(game_t *game)
{
    sfRenderWindow_drawSprite(
        game->render_window,
        game->sprites->btn_play->sprite,
        NULL
    );
}

static void draw_settings_button(game_t *game)
{
    sfRenderWindow_drawSprite(
        game->render_window,
        game->sprites->btn_settings->sprite,
        NULL
    );
}

static void draw_quit_button(game_t *game)
{
    sfRenderWindow_drawSprite(
        game->render_window,
        game->sprites->btn_quit->sprite,
        NULL
    );
}

void draw_buttons(game_t *game)
{
    draw_play_button(game);
    draw_settings_button(game);
    draw_quit_button(game);
}

void draw_main_menu_background(game_t *game)
{
    sfRenderWindow_drawSprite(
        game->render_window,
        game->sprites->main_menu_background,
        NULL
    );
}
