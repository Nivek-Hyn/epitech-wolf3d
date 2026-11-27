/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** create_text
*/

#include "wolf3d.h"

sfText *create_text(char *string, int size,
    sfColor color, sfVector2f position)
{
    sfFont *font = sfFont_createFromFile(DEFAULT_FONT);
    sfText *text = sfText_create();

    if (!font || !text)
        return NULL;
    sfText_setString(text, string);
    sfText_setCharacterSize(text, size);
    sfText_setFillColor(text, color);
    sfText_setFont(text, font);
    sfText_setPosition(text, position);
    return text;
}
