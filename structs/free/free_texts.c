/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** free_texts
*/

#include "wolf3d.h"

void free_texts(text_list_t *texts)
{
    if (texts == NULL)
        return;
    if (texts->inventory_full)
        sfText_destroy(texts->inventory_full);
    if (texts->press_x_to_interact)
        sfText_destroy(texts->press_x_to_interact);
    free(texts);
}
