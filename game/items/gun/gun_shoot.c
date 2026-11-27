/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** gun_shoot
*/

#include "wolf3d.h"

void gun_shoot(game_t *game, gun_t *gun)
{
    animation_t *anim = game->effects->gun_shot_effect;
    sfVector2f pos = {RAYCAST_WIN_X_CENTER, RAYCAST_WIN_Y_CENTER};
    sfIntRect rect = anim->animation->int_rect[0];

    anim->show = true;
    anim->anim_timer = 0.0f;
    anim->current_frame = 0;
    sfSprite_setOrigin(anim->animation->sprite,
        (sfVector2f){rect.width / 2.0f, rect.height / 2.0f});
    sfSprite_setPosition(anim->animation->sprite, pos);
}
