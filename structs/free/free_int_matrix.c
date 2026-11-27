/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** free_int_matrix
*/

#include "wolf3d.h"

void free_int_matrix(int **matrix, int y)
{
    for (int i = 0; i < y; i++)
        free(matrix[i]);
    free(matrix);
}
