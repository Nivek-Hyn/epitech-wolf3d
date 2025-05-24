/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues [WSL: Ubuntu]
** File description:
** check_buttons_event
*/

#include "wolf3d.h"

static void check_play_button_events(game_t *game)
{
    if (is_cursor_above_sprite(game->sprites->btn_play->sprite,
            game->render_window)) {
        game->sprites->btn_play->int_rect->left =
            game->sprites->btn_play->int_rect->width;
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            game->current_scene = GAME;
        }
    } else {
        game->sprites->btn_play->int_rect->left = 0;
    }
    sfSprite_setTextureRect(
        game->sprites->btn_play->sprite,
        *(game->sprites->btn_play->int_rect)
    );
}

static void check_settings_button_events(game_t *game)
{
    if (is_cursor_above_sprite(game->sprites->btn_settings->sprite,
            game->render_window)) {
        game->sprites->btn_settings->int_rect->left =
            game->sprites->btn_settings->int_rect->width;
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
        }
    } else {
        game->sprites->btn_settings->int_rect->left = 0;
    }
    sfSprite_setTextureRect(
        game->sprites->btn_settings->sprite,
        *(game->sprites->btn_settings->int_rect)
    );
}

static void check_quit_button_events(game_t *game)
{
    if (is_cursor_above_sprite(game->sprites->btn_quit->sprite,
            game->render_window)) {
        game->sprites->btn_quit->int_rect->left =
            game->sprites->btn_quit->int_rect->width;
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfRenderWindow_close(game->render_window);
        }
    } else {
        game->sprites->btn_quit->int_rect->left = 0;
    }
    sfSprite_setTextureRect(
        game->sprites->btn_quit->sprite,
        *(game->sprites->btn_quit->int_rect)
    );
}

void check_buttons_events(game_t *game)
{
    check_play_button_events(game);
    check_settings_button_events(game);
    check_quit_button_events(game);
}
