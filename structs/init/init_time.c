/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** init_time
*/

#include "wolf3d.h"

game_time_t *init_time(void)
{
    game_time_t *time = malloc(sizeof(game_time_t));

    if (!time)
        return NULL;
    time->clock = sfClock_create();
    time->delta_time = 0;
    return time;
}
