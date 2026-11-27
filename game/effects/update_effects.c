/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** update_effects
*/

#include "wolf3d.h"

void update_animation(animation_t *anim,
    float delta_time, float frame_duration)
{
    sfIntRect rect;

    if (!anim->show)
        return;
    anim->anim_timer += delta_time;
    if (anim->anim_timer >= frame_duration) {
        anim->current_frame++;
        if (anim->current_frame >= anim->animation->tile_count) {
            anim->show = false;
            anim->current_frame = 0;
        } else {
            rect = anim->animation->int_rect[anim->current_frame];
            sfSprite_setOrigin(anim->animation->sprite,
                (sfVector2f){rect.width / 2.0f, rect.height / 2.0f});
            sfSprite_setTextureRect(anim->animation->sprite,
                anim->animation->int_rect[anim->current_frame]);
        }
        anim->anim_timer = 0;
    }
}

void update_effects(game_t *game)
{
    update_animation(game->effects->gun_shot_effect,
        game->time->delta_time, FRAME_DURATION);
}
