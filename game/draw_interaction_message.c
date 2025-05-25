/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** draw_interaction_message
*/

#include "wolf3d.h"

void draw_interaction_message(game_t *game)
{
    if (game->player->can_interact)
        sfRenderWindow_drawText(game->render_window,
            game->texts->press_x_to_interact, NULL);
}
