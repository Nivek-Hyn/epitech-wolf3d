/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** init_textures
*/

#include "wolf3d.h"

void init_map_textures(world_t *world)
{
    world->wall_textures[EMPTY_WALL] =
        sfTexture_createFromFile(
            "assets/textures/walls/Rusty_Lab_Wall.jpg", NULL);
    world->wall_textures[WALL] =
        sfTexture_createFromFile(
            "assets/textures/walls/Rusty_Lab_Wall.jpg", NULL);
    world->floor_textures[EMPTY_FLOOR] =
        sfTexture_createFromFile(
            "assets/textures/floors/Concrete-Floor-Tile.png", NULL);
    world->floor_textures[WALL] =
        sfTexture_createFromFile(
            "assets/textures/floors/Concrete-Floor-Tile.png", NULL);
    world->ceiling_textures[EMPTY_CEILING] =
        sfTexture_createFromFile(
            "assets/textures/ceilings/ceiling_tile.png", NULL);
    world->ceiling_textures[WALL] =
        sfTexture_createFromFile(
            "assets/textures/ceilings/ceiling_tile.png", NULL);
}
