/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** alloc_int_matrix
*/

#include "wolf3d.h"

int **alloc_int_matrix(int y, int x)
{
    int **matrix = malloc(sizeof(int *) * y);

    for (int i = 0; i < y; i++)
        matrix[i] = malloc(sizeof(int) * x);
    return matrix;
}
