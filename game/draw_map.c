/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** draw_map
*/

#include "wolf3d.h"

void draw_map_line(game_t *game, int *map_x, int *map_y, int y)
{
    sfRectangleShape *rectangle = NULL;
    sfColor color;
    sfColor outline_color = {0, 200, 0, 255};

    for (unsigned x = 0; x < game->world->matrix_size_x; x++) {
        if (game->world->matrix[y][x] == 1) {
            color = sfWhite;
        } else {
            color = sfBlack;
        }
        rectangle = create_rectangle((sfVector2f){(*map_x), (*map_y)},
            (sfVector2f){TILE_SIZE, TILE_SIZE}, outline_color, color);
        sfRenderWindow_drawRectangleShape(game->render_window,
            rectangle, NULL);
        sfRectangleShape_destroy(rectangle);
        (*map_x) += TILE_SIZE;
    }
}

void draw_map(game_t *game)
{
    int map_y = 0;
    int map_x = 0;

    for (unsigned y = 0; y < game->world->matrix_size_y; y++) {
        draw_map_line(game, &map_x, &map_y, y);
        map_x = 0;
        map_y += TILE_SIZE;
    }
}
