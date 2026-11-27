/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** check_keyboard_events
*/

#include "wolf3d.h"

void check_keyboard_inputs(game_t *game)
{
    if (game->event.type == sfEvtKeyPressed)
        keyboard_key_pressed(game);
    if (game->event.type == sfEvtKeyReleased)
        keyboard_key_released(game);
}
