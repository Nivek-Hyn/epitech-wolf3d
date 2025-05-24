/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** key_released
*/

#include "wolf3d.h"

void numerical_keys_released(game_t *game)
{
    switch (game->event.key.code) {
    case sfKeyNum1:
        game->player->inventory->selected_slot = 0;
        break;
    case sfKeyNum2:
        game->player->inventory->selected_slot = 1;
        break;
    case sfKeyNum3:
        game->player->inventory->selected_slot = 2;
        break;
    case sfKeyNum4:
        game->player->inventory->selected_slot = 3;
        break;
    case sfKeyNum5:
        game->player->inventory->selected_slot = 4;
        break;
    }
}

void keys_released(game_t *game)
{
    switch (game->event.key.code) {
    case sfKeyF:
        game->player->flashlight = !game->player->flashlight;
        break;
    }
}

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
    numerical_keys_released(game);
    keys_released(game);
    escape_key(game);
    return;
}
