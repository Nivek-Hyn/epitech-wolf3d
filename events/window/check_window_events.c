/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** check_window_events
*/

#include "wolf3d.h"

void check_window_events(game_t *game)
{
    if (game->event.type == sfEvtClosed) {
        sfRenderWindow_close(game->render_window);
    }
    if (game->event.type == sfEvtResized) {
        window_resized(game);
    }
    if (game->event.type == sfEvtLostFocus) {
        window_lost_focus(game);
    }
    if (game->event.type == sfEvtGainedFocus) {
        window_gained_focus(game);
    }
}
