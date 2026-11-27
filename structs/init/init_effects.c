/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** init_effects
*/

#include "wolf3d.h"

effects_t *init_effects(game_t *game)
{
    effects_t *effects = malloc(sizeof(effects_t));

    if (!effects)
        return NULL;
    effects->gun_shot_effect = malloc(sizeof(animation_t));
    if (!effects->gun_shot_effect) {
        free(effects);
        return NULL;
    }
    effects->gun_shot_effect->animation =
        game->sprites->gun_shot_effect;
    effects->gun_shot_effect->anim_timer = 0.0f;
    effects->gun_shot_effect->show = false;
    effects->gun_shot_effect->current_frame = 0;
    return effects;
}
