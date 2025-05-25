/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues [WSL: Ubuntu]
** File description:
** pause_btn_load
*/

#include "wolf3d.h"

void load_map(game_t *game)
{
    free_map(game->world->map,
        game->world->map_size_x, game->world->map_size_y);
    if (load_map_file(SAVE_FILE, game->world) == -1) {
        game->world->map_size_x = STD_MATRIX_X;
        game->world->map_size_y = STD_MATRIX_Y;
        game->world->map = init_standard_map(
            game->world->map_size_x, game->world->map_size_y);
    }
    create_map(game->world);
}

static void load_paused_button_hovered(game_t *game)
{
    if (game->sprites->pause_btn_load->int_rect->left !=
        game->sprites->pause_btn_load->int_rect->width &&
        sfClock_getElapsedTime(game->settings_cooldown).microseconds
            > 100000) {
        if (game->settings->sfx_mute == false)
            sfSound_play(game->sounds->button_hover);
        game->sprites->pause_btn_load->int_rect->left =
            game->sprites->pause_btn_load->int_rect->width;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) && sfClock_getElapsedTime(
            game->settings_cooldown).microseconds > 500000) {
        sfClock_restart(game->settings_cooldown);
        if (sfSound_getStatus(game->sounds->button_click) != sfPlaying &&
            game->settings->sfx_mute == false) {
            sfSound_play(game->sounds->button_click);
        }
        load_map(game);
    }
}

void check_paused_load_button_events(game_t *game)
{
    if (is_cursor_above_sprite(game->sprites->pause_btn_load->sprite,
            game->render_window)) {
        load_paused_button_hovered(game);
    } else {
        game->sprites->pause_btn_load->int_rect->left = 0;
    }
    sfSprite_setTextureRect(
        game->sprites->pause_btn_load->sprite,
        *(game->sprites->pause_btn_load->int_rect)
    );
}
