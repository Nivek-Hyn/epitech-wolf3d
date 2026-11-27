/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** key_pressed
*/

#include "wolf3d.h"

void keys_pressed(game_t *game)
{
    switch (game->event.key.code) {
        case sfKeyLShift:
            game->extra_data->step_cooldown = PLAYER_RUN_COOLDOWN;
            game->keys->shift = 1;
            game->player->move_speed = MOVE_SPEED * 2.0f;
            break;
        default:
            break;
    }
}

void arrow_keys(game_t *game)
{
    switch (game->event.key.code) {
    case sfKeyUp:
        game->player->y -= game->player->move_speed;
        break;
    case sfKeyDown:
        game->player->y += game->player->move_speed;
        break;
    case sfKeyLeft:
        game->player->x -= game->player->move_speed;
        break;
    case sfKeyRight:
        game->player->x += game->player->move_speed;
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
    keys_pressed(game);
    return;
}
