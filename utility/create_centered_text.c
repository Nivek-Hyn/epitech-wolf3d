/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** create_centered_text
*/

#include "wolf3d.h"

sfText *create_centered_text(char *str, int size,
    sfFont *font, sfVector2f position)
{
    sfText *text = sfText_create();
    sfFloatRect bounds;

    sfText_setString(text, str);
    sfText_setCharacterSize(text, size);
    sfText_setFont(text, font);
    bounds = sfText_getLocalBounds(text);
    sfText_setOrigin(text, (sfVector2f){
        bounds.left + bounds.width / 2,
        bounds.top + bounds.height / 2
    });
    sfText_setPosition(text, position);
    return text;
}
