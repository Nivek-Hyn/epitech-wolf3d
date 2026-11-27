/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** draw_effects
*/

#include "wolf3d.h"

void draw_gun_shot_effect(game_t *game, effects_t *effects)
{
    animation_t *anim = effects->gun_shot_effect;
    float distance = 0.0f;
    float scale = 0.0f;
    float scale_factor = GUN_SHOT_EFFECT_SCALE_FACTOR;
    float scale_min = 0.1f;
    float scale_max = 10.0f;

    if (!anim->show)
        return;
    distance = game->extra_data->ray_distances[RAYCAST_WIN_WITDH / 2];
    if (distance <= 0.01f || distance > MAX_DRAW_DISTANCE)
        return;
    scale = scale_factor / (distance + 10.0f);
    if (scale > scale_max)
        scale = scale_max;
    if (scale < scale_min)
        scale = scale_min;
    sfSprite_setScale(anim->animation->sprite, (sfVector2f){scale, scale});
    sfRenderWindow_drawSprite(game->render_window,
        anim->animation->sprite, NULL);
}

void draw_effects(game_t *game, effects_t *effects)
{
    draw_gun_shot_effect(game, effects);
}
