/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** init_world
*/

#include "wolf3d.h"

void create_map_line(world_t *world, int *map_x, int *map_y, int y)
{
    sfRectangleShape *rectangle = NULL;
    sfColor color;
    sfColor outline_color = {0, 200, 0, 255};

    for (unsigned x = 0; x < world->map_size_x; x++) {
        if (world->map[y][x].type == WALL) {
            color = sfWhite;
        } else {
            color = sfBlack;
        }
        world->map[y][x].rectangle =
            create_rectangle((sfVector2f){(*map_x), (*map_y)},
                (sfVector2f){TILE_SIZE, TILE_SIZE}, outline_color, color);
        (*map_x) += TILE_SIZE;
    }
}

void create_map(world_t *world)
{
    int map_y = 0;
    int map_x = 0;

    for (unsigned y = 0; y < world->map_size_y; y++) {
        create_map_line(world, &map_x, &map_y, y);
        map_x = 0;
        map_y += TILE_SIZE;
    }
}

void copy_matrix(world_t *world,
    int map[world->map_size_y][world->map_size_x])
{
    world->map = malloc(sizeof(map_t *) * world->map_size_y);
    for (int y = 0; y < world->map_size_y; y++) {
        world->map[y] = malloc(sizeof(map_t) * world->map_size_x);
        for (int x = 0; x < world->map_size_x; x++) {
            world->map[y][x].type = map[y][x];
            world->map[y][x].texture = world->textures[map[y][x]];
        }
    }
}

void init_world_variables(world_t *world)
{
    world->map_size_x = 10;
    world->map_size_y = 10;
    world->textures[EMPTY] =
        sfTexture_createFromFile("assets/Rusty_Lab_Wall.jpg", NULL);
    world->textures[WALL] =
        sfTexture_createFromFile("assets/Rusty_Lab_Wall.jpg", NULL);
}

world_t *init_world(void)
{
    world_t *world = malloc(sizeof(world_t));
    int map[10][10] =
    {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 1, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 1, 0, 1, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    init_world_variables(world);
    copy_matrix(world, map);
    create_map(world);
    return world;
}
