/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** draw_bar
*/

#include "wolf3d.h"

void set_bar_positions(bar_components_t *bar, sfVector2f position)
{
    sfRectangleShape_setPosition(bar->background, position);
    sfRectangleShape_setPosition(bar->bar, (sfVector2f){
        position.x, position.y});
}

void center_value_text(bar_components_t *bar, sfVector2f position)
{
    sfFloatRect bounds;
    sfVector2f bar_size;

    bounds = sfText_getLocalBounds(bar->value_text);
    bar_size = bar->size;
    sfText_setOrigin(bar->value_text, (sfVector2f){
        bounds.width / 2.0f,
        bounds.height / 2.0f
    });
    sfText_setPosition(bar->value_text, (sfVector2f){
        position.x + bar_size.x / 2.0f,
        position.y + bar_size.y / 2.0f - bounds.top / 2.0f
    });
}

void center_label_text(bar_components_t *bar, sfVector2f position)
{
    sfFloatRect bounds;
    sfVector2f bar_size;

    bounds = sfText_getLocalBounds(bar->label_text);
    bar_size = bar->size;
    sfText_setOrigin(bar->label_text, (sfVector2f){
        bounds.width / 2.0f,
        bounds.height / 2.0f
    });
    sfText_setPosition(bar->label_text, (sfVector2f){
        position.x + bar_size.x / 2.0f,
        position.y - bounds.height - 5.0f
    });
}

void draw_bar_elements(sfRenderWindow *window, bar_components_t *bar)
{
    sfRenderWindow_drawRectangleShape(window, bar->background, NULL);
    sfRenderWindow_drawRectangleShape(window, bar->bar, NULL);
    sfRenderWindow_drawText(window, bar->label_text, NULL);
    sfRenderWindow_drawText(window, bar->value_text, NULL);
}

void draw_bar(sfRenderWindow *window, bar_components_t *bar,
    sfVector2f position)
{
    set_bar_positions(bar, position);
    center_value_text(bar, position);
    center_label_text(bar, position);
    draw_bar_elements(window, bar);
}
