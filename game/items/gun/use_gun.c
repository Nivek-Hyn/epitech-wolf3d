/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** use_gun
*/

#include "wolf3d.h"

void use_shoot(game_t *game, inventory_t *inventory)
{
    item_t *selected = inventory_selected_slot(inventory);
    gun_t *gun = (gun_t *)selected->data;

    if (gun->gun_anim_frame != 0)
        return;
    if (gun->ammo <= 0) {
        sfSound_play(game->sounds->empty_gun);
        return;
    } else {
        sfSound_play(game->sounds->gunshot);
        gun->ammo--;
    }
    gun->gun_anim_frame = 1;
    gun->gun_anim_timer = 0.0f;
    sfSprite_setTextureRect(
        gun->gun_ss->sprite,
        gun->gun_ss->int_rect[gun->gun_anim_frame]
    );
}
