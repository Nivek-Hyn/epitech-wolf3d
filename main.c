/*
** EPITECH PROJECT, 2025
** bs_wolf3d
** File description:
** main
*/

#include "wolf3d.h"

void scene_chooser(game_t *game)
{
    switch (game->current_scene) {
        case GAME:
            sfMusic_stop(game->sounds->menu_music);
            game_loop(game);
            break;
        case MENU_MAIN:
            main_menu_loop(game);
            break;
        case MENU_SETTINGS:
            settings_menu_loop(game);
            break;
    }
}

void render_cursor(game_t *game)
{
    sfVector2f cursor_position = {
        sfMouse_getPositionRenderWindow(game->render_window).x - 20,
        sfMouse_getPositionRenderWindow(game->render_window).y - 20
    };

    sfSprite_setPosition(game->sprites->cursor, cursor_position);
    if (game->mouse->is_locked == false) {
        sfRenderWindow_drawSprite(
            game->render_window,
            game->sprites->cursor,
            NULL
        );
    }
}

int wolf3d(void)
{
    game_t *game = init_game_struct();

    if (!game || !game->render_window || !game->player || !game->world ||
        !game->settings || !game->keys || !game->mouse || !game->time ||
        !game->fonts || !game->sprites || !game->sounds) {
        fprintf(stderr, "Wolf3d: Memory space inssufficient.\n");
        return (84);
    }
    sfRenderWindow_setFramerateLimit(game->render_window, STD_FPS);
    sfRenderWindow_setMouseCursorVisible(game->render_window, sfFalse);
    while (sfRenderWindow_isOpen(game->render_window)) {
        sfRenderWindow_clear(game->render_window, sfBlack);
        scene_chooser(game);
        render_cursor(game);
        sfRenderWindow_display(game->render_window);
    }
    free_game(game);
    return (0);
}

int main(int argc, char **argv)
{
    srand(time(NULL));
    return wolf3d();
}
