/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** is_position_an_empty_space
*/

#include "wolf3d.h"

bool is_position_an_empty_space(world_t *world, float px, float py)
{
    int tile_x = (int)(px / TILE_SIZE);
    int tile_y = (int)(py / TILE_SIZE);

    if (tile_x < 0 || tile_x >= world->map_size_x ||
        tile_y < 0 || tile_y >= world->map_size_y)
        return false;
    return world->map[tile_y][tile_x].wall_type == EMPTY_WALL;
}
