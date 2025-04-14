/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** game_loop
*/

#include "wolf3d.h"

void game_loop(game_t *game)
{
    check_events(game);
    sfRenderWindow_clear(game->render_window, sfWhite);
    sfRenderWindow_display(game->render_window);
}
