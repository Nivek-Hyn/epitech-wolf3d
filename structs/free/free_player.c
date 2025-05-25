/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** free_player
*/

#include "wolf3d.h"

void free_inventory(inventory_t *inventory)
{
    if (inventory == NULL)
        return;
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        if (inventory->slots[i].texture)
            sfTexture_destroy(inventory->slots[i].texture);
        if (inventory->slots[i].image)
            sfImage_destroy(inventory->slots[i].image);
        if (inventory->slots[i].data)
            free(inventory->slots[i].data);
        reset_inventory_slot(inventory, i);
    }
    free(inventory);
}

void free_player(player_t *player)
{
    sfCircleShape_destroy(player->player_visual);
    free_inventory(player->inventory);
    free(player);
}
