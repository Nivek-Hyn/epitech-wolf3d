/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** game_loop
*/

#include "wolf3d.h"

void draw_player(game_t *game)
{
    sfCircleShape_setPosition(game->player->player_visual,
        (sfVector2f){game->player->x, game->player->y});
    sfRenderWindow_drawCircleShape(game->render_window,
        game->player->player_visual, NULL);
}

void game_render(game_t *game)
{
    sfRenderWindow_clear(game->render_window, sfBlack);
    draw_player(game);
    sfRenderWindow_display(game->render_window);
}

void game_loop(game_t *game)
{
    check_events(game);
    game_render(game);
}
