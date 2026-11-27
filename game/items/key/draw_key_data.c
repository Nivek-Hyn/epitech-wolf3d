/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** draw_key_data
*/

#include "wolf3d.h"

void draw_key_data(game_t *game, item_t selected_slot)
{
    item_key_t *key = (item_key_t *)selected_slot.data;
    char *text = nbr_to_str(key->id);
    sfVector2f pos = {
        .x = RAYCAST_WIN_X_CENTER / 2,
        .y = RAYCAST_WIN_Y_CENTER / 2
    };

    if (key == NULL)
        return;
    draw_text(game, text, 30, pos);
    free(text);
}
