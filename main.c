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

    sfRenderWindow_setFramerateLimit(game->render_window, STD_FPS);
    while (sfRenderWindow_isOpen(game->render_window)) {
        switch (game->current_scene) {
        case GAME:
            game_loop(game);
            break;
        case MENU_MAIN:
            main_menu_loop(game);
            break;
        default:
            break;
        }
    }
    free_game(game);
    return (0);
}

int main(int argc, char **argv)
{
    srand(time(NULL));
    return wolf3d();
}
