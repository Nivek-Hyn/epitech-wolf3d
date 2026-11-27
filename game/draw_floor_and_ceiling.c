/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** draw_floor_and_ceiling
*/

#include "wolf3d.h"

void draw_floor_and_ceiling(game_t *game)
{
    sfRenderWindow_drawSprite(
        game->render_window,
        game->sprites->ceiling,
        NULL
    );
    sfRenderWindow_drawSprite(
        game->render_window,
        game->sprites->floor,
        NULL
    );
}
