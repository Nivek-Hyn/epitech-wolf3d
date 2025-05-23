/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** load_map_file
*/

#include "wolf3d.h"

void fill_wall_data(FILE *file, int **wall_data, int map_size_x,
    int map_size_y)
{
    for (int y = 0; y < map_size_y; y++)
        for (int x = 0; x < map_size_x; x++)
            fscanf(file, "%d", &wall_data[y][x]);
}

void fill_floor_data(FILE *file, int **floor_data, int map_size_x,
    int map_size_y)
{
    for (int y = 0; y < map_size_y; y++)
        for (int x = 0; x < map_size_x; x++)
            fscanf(file, "%d", &floor_data[y][x]);
}

void fill_ceiling_data(FILE *file, int **ceiling_data, int map_size_x,
    int map_size_y)
{
    for (int y = 0; y < map_size_y; y++)
        for (int x = 0; x < map_size_x; x++)
            fscanf(file, "%d", &ceiling_data[y][x]);
}

void init_world_map_data(world_t *world, int **wall_data,
    int **floor_data, int **ceiling_data)
{
    world->map = malloc(sizeof(map_t *) * world->map_size_y);
    for (int y = 0; y < world->map_size_y; y++) {
        world->map[y] = malloc(sizeof(map_t) * world->map_size_x);
        for (int x = 0; x < world->map_size_x; x++) {
            world->map[y][x].wall_type = wall_data[y][x];
            world->map[y][x].floor_type = floor_data[y][x];
            world->map[y][x].ceiling_type = ceiling_data[y][x];
        }
    }
}

void load_map_file(const char *filename, world_t *world)
{
    FILE *file = fopen(filename, "r");
    int **wall_data = NULL;
    int **floor_data = NULL;
    int **ceiling_data = NULL;

    if (!file)
        return;
    fscanf(file, "%d %d", &world->map_size_x, &world->map_size_y);
    wall_data = alloc_int_matrix(world->map_size_y, world->map_size_x);
    floor_data = alloc_int_matrix(world->map_size_y, world->map_size_x);
    ceiling_data = alloc_int_matrix(world->map_size_y, world->map_size_x);
    fill_wall_data(file, wall_data, world->map_size_x, world->map_size_y);
    fill_floor_data(file, floor_data, world->map_size_x, world->map_size_y);
    fill_ceiling_data(file, ceiling_data,
        world->map_size_x, world->map_size_y);
    init_world_map_data(world, wall_data, floor_data, ceiling_data);
    free_int_matrix(wall_data, world->map_size_y);
    free_int_matrix(floor_data, world->map_size_y);
    free_int_matrix(ceiling_data, world->map_size_y);
    fclose(file);
}
