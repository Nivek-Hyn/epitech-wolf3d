/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues [WSL: Ubuntu]
** File description:
** main_menu_loop
*/

#include "wolf3d.h"

static void main_menu_render(game_t *game)
{
    sfRenderWindow_clear(game->render_window, sfBlack);
    draw_main_menu_background_image(game);
    draw_buttons(game);
    sfRenderWindow_display(game->render_window);
}

void main_menu_sfx_manager(game_t *game)
{
    if (sfMusic_getStatus(game->sounds->menu_music) != sfPlaying) {
        sfMusic_play(game->sounds->menu_music);
    }
}

void main_menu_loop(game_t *game)
{
    main_menu_sfx_manager(game);
    check_events(game);
    check_buttons_events(game);
    main_menu_render(game);
}
