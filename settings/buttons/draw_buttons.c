/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues [WSL: Ubuntu]
** File description:
** draw_buttons
*/

#include "wolf3d.h"

static void draw_return_button(game_t *game)
{
    sfRenderWindow_drawSprite(
        game->render_window,
        game->sprites->btn_return->sprite,
        NULL
    );
}

static void draw_window_change_button(game_t *game)
{
    sfRenderWindow_drawSprite(
        game->render_window,
        game->sprites->btn_window_change->sprite,
        NULL
    );
}

void draw_settings_buttons(game_t *game)
{
    draw_return_button(game);
    draw_window_change_button(game);
}
