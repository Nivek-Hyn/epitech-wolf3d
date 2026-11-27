/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** draw_selected_item_data
*/

#include "wolf3d.h"

void draw_selected_item_data(game_t *game)
{
    item_t selected_slot = game->player->inventory->
        slots[game->player->inventory->selected_slot];
    void (*draw_data[])(game_t *game, item_t selected_slot) =
        {NULL, draw_key_data, draw_flashlight_data, draw_gun_data};

    if (selected_slot.type >= 0 && selected_slot.type < ITEM_TYPE_COUNT &&
            draw_data[selected_slot.type] != NULL)
        draw_data[selected_slot.type](game, selected_slot);
}
