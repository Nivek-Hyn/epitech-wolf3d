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

int check_circle_rectangle_collision(sfCircleShape *circle,
    sfRectangleShape *rectangle)
{
    sfVector2f circle_pos = sfCircleShape_getPosition(circle);
    float circle_radius = sfCircleShape_getRadius(circle);
    sfVector2f rectangle_pos = sfRectangleShape_getPosition(rectangle);
    sfVector2f rectangle_size = sfRectangleShape_getSize(rectangle);
    float nearest_x = clamp(circle_pos.x, rectangle_pos.x,
        rectangle_pos.x + rectangle_size.x);
    float nearest_y = clamp(circle_pos.y, rectangle_pos.y,
        rectangle_pos.y + rectangle_size.y);
    float delta_x = circle_pos.x - nearest_x;
    float delta_y = circle_pos.y - nearest_y;

    return (delta_x * delta_x + delta_y * delta_y) <
        (circle_radius * circle_radius);
}
