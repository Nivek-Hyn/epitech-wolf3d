/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** init_player
*/

#include "wolf3d.h"

inventory_t *init_inventory(void)
{
    inventory_t *inventory = malloc(sizeof(inventory_t));

    if (!inventory)
        return NULL;
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        reset_inventory_slot(inventory, i);
        inventory->slot_scales[i] = 1.0f;
    }
    inventory->selected_slot = 0;
    return inventory;
}

player_t *init_player(void)
{
    player_t *player = malloc(sizeof(player_t));

    if (!player)
        return NULL;
    player->x = TILE_SIZE + (TILE_SIZE / 2);
    player->y = TILE_SIZE + (TILE_SIZE / 2);
    player->angle = 0;
    player->delta_x = (cos(player->angle) * MOVE_SPEED);
    player->delta_y = (sin(player->angle) * MOVE_SPEED);
    player->player_visual = create_circle((sfVector2f){player->x, player->y},
        PLAYER_RADIUS, sfWhite, sfGreen);
    player->inventory = init_inventory();
    return player;
}
