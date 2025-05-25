/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues [WSL: Ubuntu]
** File description:
** btn_return_events
*/

#include "wolf3d.h"

static void back_prec_scene(game_t *game)
{
    scene_t temp_scene;

    temp_scene = game->precedent_scene;
    game->precedent_scene = game->current_scene;
    game->current_scene = temp_scene;
}

static void return_button_hovered(game_t *game)
{
    if (game->sprites->btn_return->int_rect->left !=
        game->sprites->btn_return->int_rect->width) {
        if (game->settings->sfx_mute == false)
            sfSound_play(game->sounds->button_hover);
        game->sprites->btn_return->int_rect->left =
            game->sprites->btn_return->int_rect->width;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (sfSound_getStatus(game->sounds->button_click) != sfPlaying &&
            game->settings->sfx_mute == false) {
            sfSound_play(game->sounds->button_click);
        }
        back_prec_scene(game);
    }
}

void check_return_button_events(game_t *game)
{
    if (is_cursor_above_sprite(game->sprites->btn_return->sprite,
            game->render_window)) {
        return_button_hovered(game);
    } else {
        game->sprites->btn_return->int_rect->left = 0;
    }
    sfSprite_setTextureRect(
        game->sprites->btn_return->sprite,
        *(game->sprites->btn_return->int_rect)
    );
}
