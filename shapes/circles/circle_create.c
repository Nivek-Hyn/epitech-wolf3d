/*
** EPITECH PROJECT, 2025
** my_csfml_lib
** File description:
** circle_create
*/

#include "wolf3d.h"

sfCircleShape *create_circle(sfVector2f position, float radius,
    sfColor outline_color, sfColor fill_color)
{
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setOrigin(circle, (sfVector2f){radius, radius});
    sfCircleShape_setPosition(circle, position);
    sfCircleShape_setRadius(circle, radius);
    sfCircleShape_setOutlineColor(circle, outline_color);
    sfCircleShape_setOutlineThickness(circle, 1);
    sfCircleShape_setFillColor(circle, fill_color);
    return circle;
}
