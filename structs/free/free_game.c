/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** free_game
*/

#include "wolf3d.h"

void free_game(game_t *game)
{
    free_player(game->player);
    free_settings(game->settings);
    sfRenderWindow_destroy(game->render_window);
    free(game);
}
