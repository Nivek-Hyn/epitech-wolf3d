/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues [WSL: Ubuntu]
** File description:
** btn_window_change
*/

#include "wolf3d.h"

static void fullscreen_window_change_hovered(game_t *game)
{
    if (game->sprites->btn_window_change->int_rect->left !=
        game->sprites->btn_window_change->int_rect->width * 3 &&
        sfClock_getElapsedTime(game->settings_cooldown).microseconds
            > 100000) {
        sfSound_play(game->sounds->button_hover);
    }
    game->sprites->btn_window_change->int_rect->left =
            game->sprites->btn_window_change->int_rect->width * 3;
    if (sfMouse_isButtonPressed(sfMouseLeft) && sfClock_getElapsedTime(
            game->settings_cooldown).microseconds > 500000) {
        sfClock_restart(game->settings_cooldown);
        if (sfSound_getStatus(game->sounds->button_click) != sfPlaying) {
            sfSound_play(game->sounds->button_click);
        }
        game->settings->window_mode = WINDOWED;
    }
}

static void fullscreen_window_change(game_t *game)
{
    if (is_cursor_above_sprite(game->sprites->btn_window_change->sprite,
            game->render_window)) {
        fullscreen_window_change_hovered(game);
    } else {
        game->sprites->btn_window_change->int_rect->left =
            game->sprites->btn_window_change->int_rect->width * 2;
    }
    sfSprite_setTextureRect(
        game->sprites->btn_window_change->sprite,
        *(game->sprites->btn_window_change->int_rect)
    );
}

static void windowed_window_change_hovered(game_t *game)
{
    if (game->sprites->btn_window_change->int_rect->left !=
        game->sprites->btn_window_change->int_rect->width &&
        sfClock_getElapsedTime(game->settings_cooldown).microseconds
            > 100000) {
        sfSound_play(game->sounds->button_hover);
    }
    game->sprites->btn_window_change->int_rect->left =
            game->sprites->btn_window_change->int_rect->width;
    if (sfMouse_isButtonPressed(sfMouseLeft) && sfClock_getElapsedTime(
            game->settings_cooldown).microseconds > 500000) {
        sfClock_restart(game->settings_cooldown);
        if (sfSound_getStatus(game->sounds->button_click) != sfPlaying) {
            sfSound_play(game->sounds->button_click);
        }
        game->settings->window_mode = FULLSCREEN;
    }
}

static void windowed_window_change(game_t *game)
{
    if (is_cursor_above_sprite(game->sprites->btn_window_change->sprite,
            game->render_window)) {
        windowed_window_change_hovered(game);
    } else {
        game->sprites->btn_window_change->int_rect->left = 0;
    }
    sfSprite_setTextureRect(
        game->sprites->btn_window_change->sprite,
        *(game->sprites->btn_window_change->int_rect)
    );
}

void check_window_change_button_events(game_t *game)
{
    switch (game->settings->window_mode) {
    case FULLSCREEN:
        fullscreen_window_change(game);
        break;
    case WINDOWED:
        windowed_window_change(game);
        break;
    }
}
