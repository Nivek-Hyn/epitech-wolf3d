/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues [WSL: Ubuntu]
** File description:
** btn_sfx_music_change
*/

#include "wolf3d.h"

static void off_sfx_change_hovered(game_t *game)
{
    if (game->sprites->sfx_status->int_rect->left !=
        game->sprites->sfx_status->int_rect->width * 3 &&
        sfClock_getElapsedTime(game->sfx_cooldown).microseconds
            > 100000 && game->settings->sfx_mute == false) {
        sfSound_play(game->sounds->button_hover);
    }
    game->sprites->sfx_status->int_rect->left =
            game->sprites->sfx_status->int_rect->width * 3;
    if (sfMouse_isButtonPressed(sfMouseLeft) && sfClock_getElapsedTime(
            game->sfx_cooldown).microseconds > 500000) {
        sfClock_restart(game->sfx_cooldown);
        if (sfSound_getStatus(game->sounds->button_click) != sfPlaying &&
            game->settings->sfx_mute == false) {
            sfSound_play(game->sounds->button_click);
        }
        game->settings->sfx_mute = false;
    }
}

static void off_sfx_change(game_t *game)
{
    if (is_cursor_above_sprite(game->sprites->sfx_status->sprite,
            game->render_window)) {
        off_sfx_change_hovered(game);
    } else {
        game->sprites->sfx_status->int_rect->left =
            game->sprites->sfx_status->int_rect->width * 2;
    }
    sfSprite_setTextureRect(
        game->sprites->sfx_status->sprite,
        *(game->sprites->sfx_status->int_rect)
    );
}

static void on_sfx_change_hovered(game_t *game)
{
    if (game->sprites->sfx_status->int_rect->left !=
        game->sprites->sfx_status->int_rect->width &&
        sfClock_getElapsedTime(game->sfx_cooldown).microseconds
            > 100000 && game->settings->sfx_mute == false) {
        sfSound_play(game->sounds->button_hover);
    }
    game->sprites->sfx_status->int_rect->left =
            game->sprites->sfx_status->int_rect->width;
    if (sfMouse_isButtonPressed(sfMouseLeft) && sfClock_getElapsedTime(
            game->sfx_cooldown).microseconds > 500000) {
        sfClock_restart(game->sfx_cooldown);
        if (sfSound_getStatus(game->sounds->button_click) != sfPlaying &&
            game->settings->sfx_mute == false) {
            sfSound_play(game->sounds->button_click);
        }
        game->settings->sfx_mute = true;
    }
}

static void on_sfx_change(game_t *game)
{
    if (is_cursor_above_sprite(game->sprites->sfx_status->sprite,
            game->render_window)) {
        on_sfx_change_hovered(game);
    } else {
        game->sprites->sfx_status->int_rect->left = 0;
    }
    sfSprite_setTextureRect(
        game->sprites->sfx_status->sprite,
        *(game->sprites->sfx_status->int_rect)
    );
}

void check_sfx_button_events(game_t *game)
{
    switch (game->settings->sfx_mute) {
    case false:
        on_sfx_change(game);
        break;
    case true:
        off_sfx_change(game);
        break;
    }
}
