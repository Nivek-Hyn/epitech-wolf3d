/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** draw_selected_item_data
*/

#include "wolf3d.h"

void draw_selected_item_data(game_t *game)
{
    void (*draw_data[])(game_t *game, item_t selected_slot) =
        {NULL, draw_key_data, draw_flashlight_data, draw_gun_data};
    item_t selected_slot = game->player->inventory->
        slots[game->player->inventory->selected_slot];

    if (draw_data[selected_slot.type])
        draw_data[selected_slot.type](game, selected_slot);
}
