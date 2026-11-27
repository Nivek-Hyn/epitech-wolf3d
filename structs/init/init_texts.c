/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** init_texts
*/

#include "wolf3d.h"

void create_all_texts(text_list_t *texts, font_list_t *fonts)
{
    float cx = RAYCAST_WIN_X_CENTER;
    float cy = RAYCAST_WIN_Y_CENTER;

    texts->inventory_full = create_centered_text(
        "Inventory Full", 30, fonts->normal,
            (sfVector2f){cx, cy + 225});
    sfText_setFillColor(texts->inventory_full, sfRed);
    texts->press_x_to_interact = create_centered_text(
        "Press X to interact.", 30, fonts->normal,
            (sfVector2f){cx, cy + 175});
    sfText_setFillColor(texts->press_x_to_interact, sfWhite);
}

text_list_t *init_texts(font_list_t *fonts)
{
    text_list_t *texts = malloc(sizeof(text_list_t));

    if (!texts)
        return NULL;
    create_all_texts(texts, fonts);
    return texts;
}
