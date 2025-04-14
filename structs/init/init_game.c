/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** init_game
*/

#include "wolf3d.h"

game_t *init_game_struct(void)
{
    game_t *game = malloc(sizeof(game_t));

    game->render_window = init_window();
    game->player = init_player();
    game->settings = init_settings();
    return game;
}
