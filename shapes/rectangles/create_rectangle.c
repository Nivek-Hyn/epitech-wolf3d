/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** create_rectangle
*/

#include "wolf3d.h"

sfRectangleShape *create_rectangle(sfVector2f position, sfVector2f size,
    sfColor outline_color, sfColor fill_color)
{
    sfRectangleShape *rectangle = sfRectangleShape_create();

    sfRectangleShape_setPosition(rectangle, position);
    sfRectangleShape_setSize(rectangle, size);
    sfRectangleShape_setOutlineColor(rectangle, outline_color);
    sfRectangleShape_setOutlineThickness(rectangle, 1.0);
    sfRectangleShape_setFillColor(rectangle, fill_color);
    return rectangle;
}
