/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues [WSL: Ubuntu]
** File description:
** trigonometric_functions
*/

#include "wolf3d.h"

float limit_trigo_angle(float angle)
{
    if (angle < 0)
        angle += 2 * PI;
    if (angle > 2 * PI)
        angle -= 2 * PI;
    return angle;
}

float rad(float degree)
{
    return degree * (PI / 180);
}
