/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** init_texts
*/

#include "wolf3d.h"

text_list_t *init_texts(void)
{
    text_list_t *texts = malloc(sizeof(text_list_t));

    if (!texts)
        return NULL;
    texts->inventory_full = NULL;
    texts->press_x_to_interact = NULL;
    return texts;
}
