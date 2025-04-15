/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** key_pressed
*/

#include "wolf3d.h"

void arrow_keys(game_t *game)
{
    switch (game->event.key.code) {
    case sfKeyUp:
        game->player->y -= MOVE_INCREMENTS;
        break;
    case sfKeyDown:
        game->player->y += MOVE_INCREMENTS;
        break;
    case sfKeyLeft:
        game->player->x -= MOVE_INCREMENTS;
        break;
    case sfKeyRight:
        game->player->x += MOVE_INCREMENTS;
        break;
    }
}

void keyboard_key_pressed(game_t *game)
{
    arrow_keys(game);
    return;
}
