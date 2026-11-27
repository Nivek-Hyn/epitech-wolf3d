/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues [WSL: Ubuntu]
** File description:
** free_sprite_sheet
*/

#include "wolf3d.h"

void free_sprite_sheet(sprite_sheet_t *sprite_sheet)
{
    if (!sprite_sheet)
        return;
    if (sprite_sheet->sprite) {
        sfSprite_destroy(sprite_sheet->sprite);
        sprite_sheet->sprite = NULL;
    }
    if (sprite_sheet->int_rect) {
        free(sprite_sheet->int_rect);
        sprite_sheet->int_rect = NULL;
    }
    free(sprite_sheet);
}
