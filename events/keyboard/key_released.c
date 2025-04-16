/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** key_released
*/

#include "wolf3d.h"

void zqsd_keys_released(game_t *game)
{
    switch (game->event.key.code) {
    case sfKeyQ:
        game->keys->q = 0;
        break;
    case sfKeyD:
        game->keys->d = 0;
        break;
    case sfKeyZ:
        game->keys->z = 0;
        break;
    case sfKeyS:
        game->keys->s = 0;
        break;
    case sfKeyA:
        game->keys->a = 0;
        break;
    case sfKeyE:
        game->keys->e = 0;
        break;
    }
}

void escape_key(game_t *game)
{
    if (game->event.key.code == sfKeyEscape) {
        mouse_update_lock_status(game);
    }
}

void keyboard_key_released(game_t *game)
{
    zqsd_keys_released(game);
    escape_key(game);
    return;
}
