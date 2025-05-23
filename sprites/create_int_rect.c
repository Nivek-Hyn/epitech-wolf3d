/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues [WSL: Ubuntu]
** File description:
** create_int_rect
*/

#include "wolf3d.h"

sfIntRect *create_int_rect(int top, int left, int height, int width)
{
    sfIntRect *new_rect = malloc(sizeof(sfIntRect));

    new_rect->top = top;
    new_rect->left = left;
    new_rect->height = height;
    new_rect->width = width;
    return new_rect;
}
