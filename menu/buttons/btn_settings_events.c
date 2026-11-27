/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues [WSL: Ubuntu]
** File description:
** btn_settings_events
*/

#include "wolf3d.h"

static void settings_button_hovered(game_t *game)
{
    if (game->sprites->btn_settings->int_rect->left !=
        game->sprites->btn_settings->int_rect->width &&
        sfClock_getElapsedTime(game->settings_cooldown).microseconds
            > 100000) {
        if (game->settings->sfx_mute == false)
            sfSound_play(game->sounds->button_hover);
        game->sprites->btn_settings->int_rect->left =
            game->sprites->btn_settings->int_rect->width;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) && sfClock_getElapsedTime(
            game->settings_cooldown).microseconds > 500000) {
        sfClock_restart(game->settings_cooldown);
        if (sfSound_getStatus(game->sounds->button_click) != sfPlaying &&
            game->settings->sfx_mute == false) {
            sfSound_play(game->sounds->button_click);
        }
        game->precedent_scene = game->current_scene;
        game->current_scene = MENU_SETTINGS;
    }
}

void check_settings_button_events(game_t *game)
{
    if (is_cursor_above_sprite(game->sprites->btn_settings->sprite,
            game->render_window)) {
        settings_button_hovered(game);
    } else {
        game->sprites->btn_settings->int_rect->left = 0;
    }
    sfSprite_setTextureRect(
        game->sprites->btn_settings->sprite,
        *(game->sprites->btn_settings->int_rect)
    );
}
