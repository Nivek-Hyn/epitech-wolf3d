/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** create_gun
*/

#include "wolf3d.h"

void *create_gun(void)
{
    gun_t *gun = malloc(sizeof(gun_t));
    sfTexture *texture = sfTexture_createFromFile(
        "assets/textures/items/gun_spritesheet.png", NULL);
    sprite_sheet_t *ss = create_sprite_sheet(texture, 4);

    if (!gun || !texture || !ss)
        return NULL;
    gun->sheet = texture;
    gun->gun_ss = ss;
    gun->ammo = 6;
    gun->gun_anim_frame = 0;
    gun->gun_anim_timer = 0.0f;
    sfSprite_setTextureRect(
        gun->gun_ss->sprite,
        gun->gun_ss->int_rect[0]
    );
    return (void *)gun;
}
