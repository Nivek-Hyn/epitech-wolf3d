/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** create_sprite_sheet
*/

#include "wolf3d.h"

sprite_sheet_t *create_sprite_sheet(sfTexture *texture, int frame_count)
{
    sprite_sheet_t *ss = malloc(sizeof(sprite_sheet_t));
    sfVector2u tex_size;
    int frame_width = 0;
    int frame_height = 0;

    if (!ss || !texture)
        return NULL;
    tex_size = sfTexture_getSize(texture);
    frame_width = tex_size.x / frame_count;
    frame_height = tex_size.y;
    ss->sprite = sfSprite_create();
    sfSprite_setTexture(ss->sprite, texture, sfTrue);
    ss->tile_count = frame_count;
    ss->int_rect = malloc(sizeof(sfIntRect) * frame_count);
    for (int i = 0; i < frame_count; i++)
        ss->int_rect[i] =
            (sfIntRect){i * frame_width, 0, frame_width, frame_height};
    sfSprite_setTextureRect(ss->sprite, ss->int_rect[0]);
    return ss;
}
