/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** draw_selected_item_data
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

void draw_gun_data(game_t *game, item_t selected_slot)
{
    gun_t *gun = (gun_t *)selected_slot.data;
    char *text = nbr_to_str(gun->ammo);
    sfVector2f pos = {
        .x = RAYCAST_WIN_X_CENTER / 2,
        .y = RAYCAST_WIN_Y_CENTER / 2
    };

    if (gun == NULL)
        return;
    draw_text(game, text, 30, pos);
    free(text);
}

void draw_flashlight_data(game_t *game, item_t selected_slot)
{
    flashlight_t *flashlight = (flashlight_t *)selected_slot.data;

    if (flashlight == NULL)
        return;
    draw_flashlight_battery(game, flashlight);
}

void draw_selected_item_data(game_t *game)
{
    void (*draw_data[])(game_t *game, item_t selected_slot) =
        {NULL, draw_key_data, draw_flashlight_data, draw_gun_data};
    item_t selected_slot = game->player->inventory->
        slots[game->player->inventory->selected_slot];

    if (draw_data[selected_slot.type])
        draw_data[selected_slot.type](game, selected_slot);
}
