/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** init_raycast_values
*/

#include "wolf3d.h"

void init_special_raycast_values(raycast_values_t *raycast_values)
{
    raycast_values->horizontal_dist = 0;
    raycast_values->horizontal_x = 0;
    raycast_values->horizontal_y = 0;
    raycast_values->vertical_dist = 0;
    raycast_values->vertical_x = 0;
    raycast_values->vertical_y = 0;
}

raycast_values_t *init_raycast_values(void)
{
    raycast_values_t *raycast_values = malloc(sizeof(raycast_values_t));

    if (!raycast_values)
        return NULL;
    raycast_values->r = 0;
    raycast_values->map_x = 0;
    raycast_values->map_y = 0;
    raycast_values->map_position = 0;
    raycast_values->depth_of_field = 0;
    raycast_values->ray_x = 0;
    raycast_values->ray_y = 0;
    raycast_values->ray_angle = 0;
    raycast_values->x_offset = 0;
    raycast_values->y_offset = 0;
    init_special_raycast_values(raycast_values);
    return raycast_values;
}
