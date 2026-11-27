/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues [WSL: Ubuntu]
** File description:
** pause_event
*/

#include "wolf3d.h"

void pause_event(game_t *game)
{
    switch (game->is_paused) {
    case true:
        draw_paused_menu(game);
        break;
    case false:
        break;
    }
}
