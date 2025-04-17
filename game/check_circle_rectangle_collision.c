/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** check collision between a circle and a rectangle
*/

#include "wolf3d.h"

float clamp(float value, float min, float max)
{
    if (value < min)
        return min;
    if (value > max)
        return max;
    return value;
}

int check_circle_rectangle_collision(float circle_pos_x, float circle_pos_y,
    float circle_radius, sfRectangleShape *rectangle)
{
    sfVector2f rectangle_pos = sfRectangleShape_getPosition(rectangle);
    sfVector2f rectangle_size = sfRectangleShape_getSize(rectangle);
    float nearest_x = clamp(circle_pos_x, rectangle_pos.x,
        rectangle_pos.x + rectangle_size.x);
    float nearest_y = clamp(circle_pos_y, rectangle_pos.y,
        rectangle_pos.y + rectangle_size.y);
    float delta_x = circle_pos_x - nearest_x;
    float delta_y = circle_pos_y - nearest_y;

    return (delta_x * delta_x + delta_y * delta_y) <
        (circle_radius * circle_radius);
}
