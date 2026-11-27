/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** draw_text
*/

#include "wolf3d.h"

void draw_text(game_t *game, const char *str, int size, sfVector2f pos)
{
    sfText *text = sfText_create();
    sfFloatRect bounds;

    sfText_setFont(text, game->fonts->normal);
    sfText_setString(text, str);
    sfText_setCharacterSize(text, size);
    sfText_setFillColor(text, sfWhite);
    bounds = sfText_getLocalBounds(text);
    sfText_setOrigin(text, (sfVector2f){
        bounds.left + bounds.width / 2,
        bounds.top + bounds.height / 2
    });
    sfText_setPosition(text, pos);
    sfRenderWindow_drawText(game->render_window, text, NULL);
    sfText_destroy(text);
}
