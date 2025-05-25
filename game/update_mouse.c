/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** update_mouse
*/

#include "wolf3d.h"

void mouse_update_lock_status(game_t *game)
{
    if (game->current_scene != GAME) {
        return;
    }
    if (game->mouse->is_locked == true) {
        game->mouse->is_locked = false;
        game->is_paused = true;
    } else {
        game->mouse->is_locked = true;
        game->is_paused = false;
    }
}

void mouse_mid_locked(game_t *game)
{
    sfVector2u window_size = sfRenderWindow_getSize(game->render_window);
    sfVector2i middle_point =
        {.x = (window_size.x / 2), .y = (window_size.y / 2)};

    sfMouse_setPositionRenderWindow(middle_point, game->render_window);
    game->mouse->previous_position = middle_point;
}

void update_mouse(game_t *game)
{
    if (game->mouse->is_locked == true) {
        mouse_mid_locked(game);
    }
}
