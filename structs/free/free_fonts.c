/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** free_fonts
*/

#include "wolf3d.h"

void free_fonts(font_list_t *fonts)
{
    if (fonts == NULL)
        return;
    sfFont_destroy(fonts->normal);
    sfFont_destroy(fonts->arial);
    free(fonts);
}
