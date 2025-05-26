/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues [WSL: Ubuntu]
** File description:
** init_floor_ceiling
*/

#include "wolf3d.h"

void init_floor(sprites_t *sprites, extra_data_t *extra_data)
{
    sprites->floor = sprite_create(
        "assets/textures/floors/Floor.png",
        4,
        (sfVector2f){0, STD_WIN_HEIGHT / 2},
        extra_data
    );
}

void init_ceiling(sprites_t *sprites, extra_data_t *extra_data)
{
    sprites->ceiling = sprite_create(
        "assets/textures/ceilings/Sky.jpg",
        1.6,
        (sfVector2f){0, -600},
        extra_data
    );
}
