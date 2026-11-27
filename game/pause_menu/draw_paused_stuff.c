/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues [WSL: Ubuntu]
** File description:
** draw_paused_stuff
*/

#include "wolf3d.h"

static void draw_paused_background(game_t *game)
{
    sfRenderWindow_drawSprite(
        game->render_window,
        game->sprites->pause_menu_background,
        NULL
    );
}

void draw_paused_buttons(game_t *game)
{
    sfRenderWindow_drawSprite(
        game->render_window,
        game->sprites->pause_btn_settings->sprite,
        NULL
    );
    sfRenderWindow_drawSprite(
        game->render_window,
        game->sprites->pause_btn_menu->sprite,
        NULL
    );
    sfRenderWindow_drawSprite(
        game->render_window,
        game->sprites->pause_btn_save->sprite,
        NULL
    );
    sfRenderWindow_drawSprite(
        game->render_window,
        game->sprites->pause_btn_load->sprite,
        NULL
    );
}

void draw_paused_menu(game_t *game)
{
    draw_paused_background(game);
    draw_paused_buttons(game);
    update_paused_buttons(game);
}
