/*
** EPITECH PROJECT, 2025
** bs_wolf3d
** File description:
** main
*/

#include "wolf3d.h"

int wolf3d(void)
{
    game_t *game = init_game_struct();

    sfRenderWindow_setFramerateLimit(game->render_window, 60);
    while (sfRenderWindow_isOpen(game->render_window)) {
        game_loop(game);
    }
    free_game(game);
    return 0;
}

int main(int argc, char **argv)
{
    return wolf3d();
}
