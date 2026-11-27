/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** free_time
*/

#include "wolf3d.h"

void free_time(game_time_t *time)
{
    if (time == NULL)
        return;
    sfClock_destroy(time->clock);
    free(time);
}
