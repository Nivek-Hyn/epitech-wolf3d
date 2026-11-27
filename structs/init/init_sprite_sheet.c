/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues [WSL: Ubuntu]
** File description:
** init_sprite_sheet
*/

#include "wolf3d.h"

sprite_sheet_t *init_sprite_sheet(int tile_count,
    sfSprite *sprite, sfIntRect *int_rect)
{
    sprite_sheet_t *sprite_sheet = malloc(sizeof(sprite_sheet_t));

    if (sprite_sheet == NULL)
        return NULL;
    sprite_sheet->tile_count = tile_count;
    sprite_sheet->sprite = sprite;
    sprite_sheet->int_rect = int_rect;
    sfSprite_setTextureRect(sprite_sheet->sprite, *sprite_sheet->int_rect);
    return sprite_sheet;
}
