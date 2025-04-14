/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** init_world
*/

#include "wolf3d.h"

world_t *world_init(void)
{
    world_t *world = malloc(sizeof(world_t));

    world->matrix = rand_matrix_create(STD_MATRIX_X, STD_MATRIX_Y);
    world->matrix_size_x = STD_MATRIX_X;
    world->matrix_size_y = STD_MATRIX_Y;
    return world;
}
