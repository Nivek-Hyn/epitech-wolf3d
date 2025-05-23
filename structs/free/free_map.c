/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** free_game
*/

#include "wolf3d.h"

void free_tile(map_t **map, int x, int y)
{
    if (map[y][x].wall_rectangle)
        sfRectangleShape_destroy(map[y][x].wall_rectangle);
}

void free_map(map_t **map, int map_size_x, int map_size_y)
{
    for (int y = 0; y < map_size_y; y++) {
        for (int x = 0; x < map_size_x; x++) {
            free_tile(map, x, y);
        }
        free(map[y]);
    }
    free(map);
}
