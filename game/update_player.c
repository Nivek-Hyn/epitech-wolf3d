/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** update_player
*/

#include "wolf3d.h"

void update_player_angle(game_t *game)
{
    if (game->keys->a == 1) {
        game->player->angle -= 0.1;
        if (game->player->angle < 0)
            game->player->angle += (2 * PI);
        game->player->delta_x = (cos(game->player->angle) * MOVE_SPEED);
        game->player->delta_y = (sin(game->player->angle) * MOVE_SPEED);
    }
    if (game->keys->e == 1) {
        game->player->angle += 0.1;
        if (game->player->angle < (2 * PI))
            game->player->angle -= (2 * PI);
        game->player->delta_x = (cos(game->player->angle) * MOVE_SPEED);
        game->player->delta_y = (sin(game->player->angle) * MOVE_SPEED);
    }
}

void update_player_movement_vector(game_t *game, float *move_x, float *move_y)
{
    if (game->keys->z == 1) {
        (*move_x) += game->player->delta_x;
        (*move_y) += game->player->delta_y;
    }
    if (game->keys->s == 1) {
        (*move_x) -= game->player->delta_x;
        (*move_y) -= game->player->delta_y;
    }
    if (game->keys->q == 1) {
        (*move_x) += game->player->delta_y;
        (*move_y) -= game->player->delta_x;
    }
    if (game->keys->d == 1) {
        (*move_x) -= game->player->delta_y;
        (*move_y) += game->player->delta_x;
    }
}

void apply_player_normalized_movement(game_t *game,
    float *move_x, float *move_y)
{
    float vector_length = 0;

    vector_length = sqrt((*move_x) * (*move_x) + (*move_y) * (*move_y));
    if (vector_length > 0) {
        (*move_x) /= vector_length;
        (*move_y) /= vector_length;
    }
    game->player->x += (*move_x) * MOVE_SPEED;
    game->player->y += (*move_y) * MOVE_SPEED;
}

void update_player(game_t *game)
{
    float move_x = 0;
    float move_y = 0;

    update_player_angle(game);
    update_player_movement_vector(game, &move_x, &move_y);
    apply_player_normalized_movement(game, &move_x, &move_y);
}
