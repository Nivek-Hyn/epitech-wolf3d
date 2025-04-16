/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** free_world
*/

#include "wolf3d.h"

void free_world(world_t *world)
{
    free_map(world->map, world->map_size_x, world->map_size_y);
    free(world);
}
