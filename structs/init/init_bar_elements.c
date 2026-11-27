/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** init_bar_elements
*/

#include "wolf3d.h"

void init_bar_components(bar_components_t *bar)
{
    bar->background = sfRectangleShape_create();
    bar->bar = sfRectangleShape_create();
    bar->value_text = sfText_create();
    bar->label_text = sfText_create();
    sfRectangleShape_setSize(bar->background, bar->size);
    sfRectangleShape_setFillColor(bar->background, bar->background_color);
    sfRectangleShape_setOutlineColor(bar->background, bar->outline_color);
    sfRectangleShape_setOutlineThickness(
        bar->background, bar->outline_thickness);
    sfText_setFont(bar->value_text, bar->font);
    sfText_setCharacterSize(bar->value_text, bar->value_text_size);
    sfText_setFillColor(bar->value_text, bar->value_text_color);
    sfText_setFont(bar->label_text, bar->font);
    sfText_setCharacterSize(bar->label_text, bar->label_text_size);
    sfText_setFillColor(bar->label_text, bar->label_text_color);
}
