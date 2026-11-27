/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** btn_released
*/

#include "wolf3d.h"

void mouse_button_released(game_t *game)
{
    if (game->event.type == sfEvtMouseButtonReleased &&
        game->event.mouseButton.button == sfMouseLeft) {
        use_selected_item(game, game->player->inventory);
    }
    return;
}
