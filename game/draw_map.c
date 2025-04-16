/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** draw_map
*/

#include "wolf3d.h"

void draw_map(game_t *game)
{
    for (int y = 0; y < game->world->map_size_y; y++) {
        for (int x = 0; x < game->world->map_size_x; x++) {
            sfRenderWindow_drawRectangleShape(game->render_window,
                game->world->map[y][x].rectangle, NULL);
        }
    }
}
