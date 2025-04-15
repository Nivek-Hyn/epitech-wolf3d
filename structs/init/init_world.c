/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** init_world
*/

#include "wolf3d.h"

void copy_matrix(world_t *world,
    int matrix[world->matrix_size_y][world->matrix_size_x])
{
    world->matrix = malloc(sizeof(int *) * world->matrix_size_y);
    for (int i = 0; i < world->matrix_size_y; i++) {
        world->matrix[i] = malloc(sizeof(int) * world->matrix_size_x);
        for (int j = 0; j < world->matrix_size_x; j++) {
            world->matrix[i][j] = matrix[i][j];
        }
    }
}

world_t *init_world(void)
{
    world_t *world = malloc(sizeof(world_t));
    int matrix[10][10] =
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

    world->matrix_size_x = 10;
    world->matrix_size_y = 10;
    copy_matrix(world, matrix);
    return world;
}
