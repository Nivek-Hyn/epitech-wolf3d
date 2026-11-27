/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** init_mouse
*/

#include "wolf3d.h"

mouse_t *init_mouse(void)
{
    mouse_t *mouse = malloc(sizeof(mouse_t));

    if (!mouse)
        return NULL;
    mouse->delta_x = 0;
    mouse->sensivity = MOUSE_SENSITIVITY;
    mouse->previous_position = (sfVector2i){0, 0};
    mouse->is_locked = true;
    return mouse;
}
