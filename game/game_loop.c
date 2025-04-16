/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** game_loop
*/

#include "wolf3d.h"

void game_render(game_t *game)
{
    sfRenderWindow_clear(game->render_window, sfBlack);
    draw_map(game);
    draw_player(game);
    sfRenderWindow_display(game->render_window);
}

void game_loop(game_t *game)
{
    check_events(game);
    update_player(game);
    update_mouse(game);
    game_render(game);
}
