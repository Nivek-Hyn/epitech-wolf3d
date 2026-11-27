/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** free_player
*/

#include "wolf3d.h"

void free_health(health_t *health)
{
    if (health == NULL)
        return;
    if (health->health_bar) {
        sfRectangleShape_destroy(health->health_bar->background);
        sfRectangleShape_destroy(health->health_bar->bar);
        sfText_destroy(health->health_bar->value_text);
        sfText_destroy(health->health_bar->label_text);
        free(health->health_bar);
    }
    free(health);
}

void free_stamina(stamina_t *stamina)
{
    if (stamina == NULL)
        return;
    if (stamina->stamina_bar) {
        sfRectangleShape_destroy(stamina->stamina_bar->background);
        sfRectangleShape_destroy(stamina->stamina_bar->bar);
        sfText_destroy(stamina->stamina_bar->value_text);
        sfText_destroy(stamina->stamina_bar->label_text);
        free(stamina->stamina_bar);
    }
    free(stamina);
}

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
            free_item_data(inventory->slots[i].data, inventory->slots[i].type);
        reset_inventory_slot(inventory, i);
    }
    free(inventory);
}

void free_player(player_t *player)
{
    sfCircleShape_destroy(player->player_visual);
    free_inventory(player->inventory);
    free_health(player->health);
    free_stamina(player->stamina);
    free(player);
}
