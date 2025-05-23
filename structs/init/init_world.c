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
        if (world->map[y][x].wall_type == WALL) {
            color = sfWhite;
        } else {
            color = sfBlack;
        }
        world->map[y][x].wall_rectangle =
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

void init_world_variables(world_t *world)
{
    world->map_size_x = 0;
    world->map_size_y = 0;
    world->wall_textures[EMPTY_WALL] =
        sfTexture_createFromFile("assets/Rusty_Lab_Wall.jpg", NULL);
    world->wall_textures[WALL] =
        sfTexture_createFromFile("assets/Rusty_Lab_Wall.jpg", NULL);
    world->floor_textures[EMPTY_FLOOR] =
        sfTexture_createFromFile("assets/Rusty_Lab_Wall.jpg", NULL);
    world->floor_textures[WALL] =
        sfTexture_createFromFile("assets/Rusty_Lab_Wall.jpg", NULL);
    world->ceiling_textures[EMPTY_CEILING] =
        sfTexture_createFromFile("assets/Rusty_Lab_Wall.jpg", NULL);
    world->ceiling_textures[WALL] =
        sfTexture_createFromFile("assets/Rusty_Lab_Wall.jpg", NULL);
}

world_t *init_world(void)
{
    world_t *world = malloc(sizeof(world_t));

    init_world_variables(world);
    load_map_file("save.txt", world);
    create_map(world);
    return world;
}
