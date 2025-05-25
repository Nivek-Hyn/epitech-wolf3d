/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** use_selected_item
*/

#include "wolf3d.h"

void use_key(game_t *game, inventory_t *inventory)
{
    return;
}

void use_gun(game_t *game, inventory_t *inventory)
{
    item_t *selected = inventory_selected_slot(inventory);
    gun_t *gun = (gun_t *)selected->data;

    if (gun->gun_anim_frame != 0 || gun->ammo <= 0)
        return;
    gun->ammo--;
    gun->gun_anim_frame = 1;
    gun->gun_anim_timer = 0.0f;
    sfSprite_setTextureRect(
        gun->gun_ss->sprite,
        gun->gun_ss->int_rect[gun->gun_anim_frame]
    );
}

void use_selected_item(game_t *game, inventory_t *inventory)
{
    switch (inventory->slots[inventory->selected_slot].type) {
        case ITEM_KEY:
            use_key(game, inventory);
            break;
        case ITEM_FLASHLIGHT:
            turn_flashlight(game);
            break;
        case ITEM_GUN:
            use_gun(game, inventory);
            break;
    }
}
