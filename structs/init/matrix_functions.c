/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** matrix_functions
*/

#include "wolf3d.h"

int **blank_matrix_create(int map_size_x, int map_size_y)
{
    int **map = malloc(sizeof(int *) * map_size_y);

    if (!map)
        return NULL;
    for (unsigned i = 0; i < map_size_y; i++) {
        map[i] = malloc(sizeof(int) * map_size_x);
        if (!map[i])
            return NULL;
        for (unsigned j = 0; j < map_size_x; j++) {
            map[i][j] = 0;
        }
    }
    return map;
}

int **rand_matrix_create(int map_size_x, int map_size_y)
{
    int **map = malloc(sizeof(int *) * map_size_y);

    if (!map)
        return NULL;
    for (unsigned i = 0; i < map_size_y; i++) {
        map[i] = malloc(sizeof(int) * map_size_x);
        if (!map[i])
            return NULL;
        for (unsigned j = 0; j < map_size_x; j++) {
            map[i][j] = rand() % 2;
        }
    }
    return map;
}

void matrix_display(int **map, int map_size_x, int map_size_y)
{
    for (unsigned i = 0; i < map_size_y; i++) {
        for (unsigned j = 0; j < map_size_x; j++) {
            printf("%d", map[i][j]);
        }
        printf("\n");
    }
}
