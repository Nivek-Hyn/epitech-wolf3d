/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** set_circle_position
*/

#include "wolf3d.h"

// Overwrite precedent position with a new one, from the circle's center.
void set_circle_position(sfCircleShape *shape, sfVector2f position)
{
    float radius = sfCircleShape_getRadius(shape);

    position.x -= radius;
    position.y -= radius;
    sfCircleShape_setPosition(shape, position);
}
