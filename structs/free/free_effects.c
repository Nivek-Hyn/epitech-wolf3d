/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** free_effects
*/

#include "wolf3d.h"

void free_effects(effects_t *effects)
{
    if (!effects)
        return;
    if (effects->gun_shot_effect) {
        if (effects->gun_shot_effect->animation) {
            free_sprite_sheet(effects->gun_shot_effect->animation);
            effects->gun_shot_effect->animation = NULL;
        }
        free(effects->gun_shot_effect);
    }
    free(effects);
}
