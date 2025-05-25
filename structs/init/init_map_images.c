/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** init_map_images
*/

#include "wolf3d.h"

void init_map_images(world_t *world)
{
    world->floor_images[EMPTY_FLOOR] =
        sfImage_createFromFile(
            "assets/textures/floors/floor_tile.jpg");
    world->floor_images[FLOOR] =
        sfImage_createFromFile(
            "assets/textures/floors/floor_tile.jpg");
    world->ceiling_images[EMPTY_CEILING] =
        sfImage_createFromFile(
            "assets/textures/ceilings/ceiling_tile.png");
    world->ceiling_images[CEILING] =
        sfImage_createFromFile(
            "assets/textures/ceilings/ceiling_tile.png");
}
