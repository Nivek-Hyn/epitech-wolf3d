/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** intrect_create
*/

#include "wolf3d.h"

sfIntRect *intrect_create(int top, int left, int height, int width)
{
    sfIntRect *new_rect = malloc(sizeof(sfIntRect));

    new_rect->top = top;
    new_rect->left = left;
    new_rect->height = height;
    new_rect->width = width;
    return new_rect;
}
