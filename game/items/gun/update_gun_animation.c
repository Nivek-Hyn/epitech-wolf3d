/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** update_gun_animation
*/

#include "wolf3d.h"

void gun_shoot(game_t *game, gun_t *gun)
{
    printf("Shoot !\n");
}

void update_gun_animation(game_t *game)
{
    item_t *selected = inventory_selected_slot(game->player->inventory);
    gun_t *gun = NULL;

    if (selected->type != ITEM_GUN || selected->data == NULL)
        return;
    gun = (gun_t *)selected->data;
    if (gun->gun_anim_frame == 0)
        return;
    gun->gun_anim_timer += game->time->delta_time;
    if (gun->gun_anim_timer >= FRAME_DURATION) {
        gun->gun_anim_timer = 0.0f;
        gun->gun_anim_frame++;
        if (gun->gun_anim_frame == SHOOT_TRIGGER_FRAME)
            gun_shoot(game, gun);
        if (gun->gun_anim_frame >= gun->gun_ss->tile_count)
            gun->gun_anim_frame = 0;
    }
    sfSprite_setTextureRect(gun->gun_ss->sprite,
        gun->gun_ss->int_rect[gun->gun_anim_frame]);
}
