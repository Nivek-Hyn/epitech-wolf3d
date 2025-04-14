/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** circle_intersection
*/

#include "wolf3d.h"

sfBool are_circles_intersecting(sfCircleShape *c1, sfCircleShape *c2)
{
    sfVector2f pos_c1 = sfCircleShape_getPosition(c1);
    sfVector2f pos_c2 = sfCircleShape_getPosition(c2);
    float Cr = sfCircleShape_getRadius(c1);
    float Dr = sfCircleShape_getRadius(c2);
    float Cx = pos_c1.x + Cr;
    float Cy = pos_c1.y + Cr;
    float Dx = pos_c2.x + Dr;
    float Dy = pos_c2.y + Dr;

    if ((((Cx - Dx) * (Cx - Dx)) + ((Cy - Dy) * (Cy - Dy)))
        <= (((Cr + Dr)) * ((Cr + Dr)))) {
        return (sfTrue);
    } else {
        return (sfFalse);
    }
}
