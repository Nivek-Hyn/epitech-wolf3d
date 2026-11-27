/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** draw_items
*/

#include "wolf3d.h"

void draw_items(game_t *game)
{
    world_item_t *item = NULL;

    for (int i = 0; i < MAX_WORLD_ITEMS; i++) {
        item = &game->item_manager->world_items[i];
        if (item->item.type != ITEM_NONE && item->circle_visual &&
                is_position_an_empty_space(game->world,
                    item->position.x, item->position.y)) {
            sfRenderWindow_drawCircleShape(game->render_window,
                item->circle_visual, NULL);
        }
    }
}
