/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** init_world
*/

#include "wolf3d.h"

void create_map_tile(map_t *map, int *map_x, int *map_y)
{
    sfColor color = (map->wall_type == WALL) ? WALL_MAP_COLOR : sfBlack;
    sfColor outline_color = {WALL_MAP_OUTLINE_COLOR};

    map->wall_rectangle =
        create_rectangle((sfVector2f){(*map_x), (*map_y)},
            (sfVector2f){TILE_SIZE, TILE_SIZE}, outline_color, color);
    color = (map->wall_type == WALL) ? WALL_MAP_COLOR : sfBlack;
    outline_color = (sfColor){FLOOR_MAP_OUTLINE_COLOR};
    map->floor_rectangle =
        create_rectangle((sfVector2f){(*map_x), (*map_y)},
            (sfVector2f){TILE_SIZE, TILE_SIZE}, outline_color, color);
    color = (map->wall_type == WALL) ? WALL_MAP_COLOR : sfBlack;
    outline_color = (sfColor){CEILING_MAP_OUTLINE_COLOR};
    map->ceiling_rectangle =
        create_rectangle((sfVector2f){(*map_x), (*map_y)},
            (sfVector2f){TILE_SIZE, TILE_SIZE}, outline_color, color);
}

void create_map_line(world_t *world, int *map_x, int *map_y, int y)
{
    for (unsigned x = 0; x < world->map_size_x; x++) {
        create_map_tile(&world->map[y][x], map_x, map_y);
        (*map_x) += TILE_SIZE;
    }
}

void create_map(world_t *world)
{
    int map_x = MAP_X;
    int map_y = MAP_Y;

    for (unsigned y = 0; y < world->map_size_y; y++) {
        create_map_line(world, &map_x, &map_y, y);
        map_x = MAP_X;
        map_y += TILE_SIZE;
    }
}

void init_world_variables(world_t *world)
{
    world->map_size_x = 0;
    world->map_size_y = 0;
    init_map_textures(world);
    init_map_images(world);
}

world_t *init_world(void)
{
    world_t *world = malloc(sizeof(world_t));

    init_world_variables(world);
    load_map_file("save.txt", world);
    create_map(world);
    return world;
}
