/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** is_cursor_above_sprite
*/

#include "wolf3d.h"

bool is_cursor_above_sprite(sfSprite *sprite, sfRenderWindow *render_window)
{
    sfVector2i pos_curs = sfMouse_getPositionRenderWindow(render_window);
    sfFloatRect sprite_bounds = sfSprite_getGlobalBounds(sprite);

    if (pos_curs.x >= sprite_bounds.left &&
        pos_curs.x <= sprite_bounds.left + sprite_bounds.width &&
        pos_curs.y >= sprite_bounds.top &&
        pos_curs.y <= sprite_bounds.top + sprite_bounds.height) {
        return true;
    }
    return false;
}
