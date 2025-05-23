/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues [WSL: Ubuntu]
** File description:
** main_menu_loop
*/

#include "wolf3d.h"

void draw_main_menu_background_image(game_t *game)
{
    sfRenderWindow_drawSprite(
        game->render_window,
        game->sprites->main_menu_background,
        NULL
    );
}

void main_menu_render(game_t *game)
{
    sfRenderWindow_clear(game->render_window, sfBlack);
    draw_main_menu_background_image(game);
    sfRenderWindow_display(game->render_window);
}

void main_menu_loop(game_t *game)
{
    check_events(game);
    main_menu_render(game);
}
