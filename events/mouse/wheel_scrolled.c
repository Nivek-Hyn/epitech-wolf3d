/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** wheel_scrolled
*/

#include "wolf3d.h"

void mouse_wheel_scrolled(game_t *game)
{
    if (game->event.mouseWheelScroll.delta > 0) {
        inventory_select_next_slot(game->player->inventory);
    } else {
        inventory_select_previous_slot(game->player->inventory);
    }
    return;
}
