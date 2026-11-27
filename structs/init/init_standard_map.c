/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** init_standard_map
*/

#include "wolf3d.h"

map_t **init_standard_map(int map_size_x, int map_size_y)
{
    map_t **map = malloc(sizeof(map_t *) * map_size_y);

    if (!map)
        return NULL;
    for (int y = 0; y < map_size_y; y++) {
        map[y] = malloc(sizeof(map_t) * map_size_x);
        for (int x = 0; x < map_size_x; x++) {
            map[y][x].wall_type = EMPTY_WALL;
            map[y][x].floor_type = EMPTY_FLOOR;
            map[y][x].ceiling_type = EMPTY_CEILING;
        }
    }
    return map;
}
