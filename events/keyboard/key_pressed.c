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
        game->player->y -= MOVE_SPEED;
        break;
    case sfKeyDown:
        game->player->y += MOVE_SPEED;
        break;
    case sfKeyLeft:
        game->player->x -= MOVE_SPEED;
        break;
    case sfKeyRight:
        game->player->x += MOVE_SPEED;
        break;
    }
}

void zqsd_keys_pressed(game_t *game)
{
    switch (game->event.key.code) {
    case sfKeyQ:
        game->keys->q = 1;
        break;
    case sfKeyD:
        game->keys->d = 1;
        break;
    case sfKeyZ:
        game->keys->z = 1;
        break;
    case sfKeyS:
        game->keys->s = 1;
        break;
    case sfKeyA:
        game->keys->a = 1;
        break;
    case sfKeyE:
        game->keys->e = 1;
        break;
    }
}

void keyboard_key_pressed(game_t *game)
{
    arrow_keys(game);
    zqsd_keys_pressed(game);
    return;
}
