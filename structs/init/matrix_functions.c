/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** matrix_functions
*/

#include "wolf3d.h"

int **blank_matrix_create(int matrix_size_x, int matrix_size_y)
{
    int **matrix = malloc(sizeof(int *) * matrix_size_y);

    for (unsigned i = 0; i < matrix_size_y; i++) {
        matrix[i] = malloc(sizeof(int) * matrix_size_x);
        for (unsigned j = 0; j < matrix_size_x; j++) {
            matrix[i][j] = 0;
        }
    }
    return matrix;
}

int **rand_matrix_create(int matrix_size_x, int matrix_size_y)
{
    int **matrix = malloc(sizeof(int *) * matrix_size_y);

    for (unsigned i = 0; i < matrix_size_y; i++) {
        matrix[i] = malloc(sizeof(int) * matrix_size_x);
        for (unsigned j = 0; j < matrix_size_x; j++) {
            matrix[i][j] = rand() % 2;
        }
    }
    return matrix;
}

void matrix_display(int **matrix, int matrix_size_x, int matrix_size_y)
{
    for (unsigned i = 0; i < matrix_size_y; i++) {
        for (unsigned j = 0; j < matrix_size_x; j++) {
            printf("%d", matrix[i][j]);
        }
    }
}
