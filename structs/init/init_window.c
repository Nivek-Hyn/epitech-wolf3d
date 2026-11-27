/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** init_window
*/

#include "wolf3d.h"

sfRenderWindow *init_window(void)
{
    char *win_name = STD_WIN_TITLE;
    sfVideoMode mode = {STD_WIN_WIDTH, STD_WIN_HEIGHT, 32};
    sfRenderWindow *window =
        sfRenderWindow_create(mode, win_name, sfTitlebar | sfClose, NULL);

    return window;
}

void init_changed_render_window(game_t *game)
{
    char *win_name = STD_WIN_TITLE;
    sfVideoMode mode = {
        game->settings->window_width,
        game->settings->window_height,
        32
    };
    unsigned render_window_style_modes = 0;

    if (game->settings->window_mode == FULLSCREEN)
        render_window_style_modes = sfFullscreen;
    else if (game->settings->window_mode == WINDOWED) {
        render_window_style_modes = (sfTitlebar | sfClose);
    }
    sfRenderWindow_destroy(game->render_window);
    game->render_window = sfRenderWindow_create(
        mode, win_name, render_window_style_modes, NULL);
    sfRenderWindow_setFramerateLimit(game->render_window, STD_FPS);
    sfRenderWindow_setMouseCursorVisible(game->render_window, sfFalse);
}
