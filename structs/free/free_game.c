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
    free_world(game->world);
    free_settings(game->settings);
    free_keys(game->keys);
    free_mouse(game->mouse);
    free_time(game->time);
    free_fonts(game->fonts);
    free_sprites(game);
    free_sfx(game->sounds);
    sfRenderWindow_destroy(game->render_window);
    free(game);
}
