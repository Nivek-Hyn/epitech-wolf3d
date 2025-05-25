/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** init_fonts
*/

#include "wolf3d.h"

font_list_t *init_fonts(void)
{
    font_list_t *fonts = malloc(sizeof(font_list_t));

    if (!fonts)
        return NULL;
    fonts->normal = sfFont_createFromFile(DEFAULT_FONT);
    fonts->arial = sfFont_createFromFile(ARIAL_FONT);
    if (!fonts->normal) {
        free(fonts);
        return NULL;
    }
    return fonts;
}
