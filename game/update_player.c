/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** update_player
*/

#include "wolf3d.h"

void player_angle_mouse(game_t *game)
{
    float movement_speed = 0.0;
    sfVector2i current_position =
        sfMouse_getPositionRenderWindow(game->render_window);

    game->mouse->delta_x =
        current_position.x - game->mouse->previous_position.x;
    movement_speed = STD_LOOK_SPEED * abs(game->mouse->delta_x)
        * game->mouse->sensivity;
    if (game->mouse->delta_x > 0) {
        player_look_right(game, movement_speed);
    } else if (game->mouse->delta_x < 0) {
        player_look_left(game, movement_speed);
    }
    game->mouse->previous_position = current_position;
}

void update_player_angle(game_t *game)
{
    player_angle_mouse(game);
    if (game->keys->a == 1) {
        player_look_left(game, STD_LOOK_SPEED);
    }
    if (game->keys->e == 1) {
        player_look_right(game, STD_LOOK_SPEED);
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
    float speed = MOVE_SPEED * game->time->delta_time;

    vector_length = sqrt((*move_x) * (*move_x) + (*move_y) * (*move_y));
    if (vector_length > 0) {
        (*move_x) /= vector_length;
        (*move_y) /= vector_length;
    }
    if (check_player_walls_collision(game->player->x + (*move_x) * speed,
        game->player->y, game) != 1) {
        game->player->x += (*move_x) * speed;
    }
    if (check_player_walls_collision(game->player->x,
        game->player->y + (*move_y) * speed,
        game) != 1) {
        game->player->y += (*move_y) * speed;
    }
}

static void play_random_footstep(game_t *game)
{
    int random_index = rand() % 3;
    sfSound *footstep_sounds[] = {
        game->sounds->footstep,
        game->sounds->footstep_two,
        game->sounds->footstep_three,
        game->sounds->footstep_four
    };

    sfSound_play(footstep_sounds[random_index]);
}

static void footstep_sfx(game_t *game)
{
    if (game->keys->z == 1 || game->keys->s == 1 ||
        game->keys->q == 1 || game->keys->d == 1) {
        if (sfClock_getElapsedTime(game->extra_data->step_clock).microseconds
            < game->extra_data->step_cooldown) {
            return;
        }
        sfClock_restart(game->extra_data->step_clock);
        play_random_footstep(game);
    }
}

void update_player(game_t *game)
{
    float move_x = 0;
    float move_y = 0;

    footstep_sfx(game);
    update_player_angle(game);
    update_player_movement_vector(game, &move_x, &move_y);
    apply_player_normalized_movement(game, &move_x, &move_y);
    update_player_flashlight_battery(game);
}
