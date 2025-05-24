/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues [WSL: Ubuntu]
** File description:
** btn_quit_events
*/

#include "wolf3d.h"

static void quit_button_hovered(game_t *game)
{
    if (game->sprites->btn_quit->int_rect->left !=
        game->sprites->btn_quit->int_rect->width){
        sfSound_play(game->sounds->button_hover);
        game->sprites->btn_quit->int_rect->left =
            game->sprites->btn_quit->int_rect->width;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (sfSound_getStatus(game->sounds->button_click) != sfPlaying) {
            sfSound_play(game->sounds->button_click);
        }
        sfRenderWindow_close(game->render_window);
    }
}

void check_quit_button_events(game_t *game)
{
    if (is_cursor_above_sprite(game->sprites->btn_quit->sprite,
            game->render_window)) {
        quit_button_hovered(game);
    } else {
        game->sprites->btn_quit->int_rect->left = 0;
    }
    sfSprite_setTextureRect(
        game->sprites->btn_quit->sprite,
        *(game->sprites->btn_quit->int_rect)
    );
}
