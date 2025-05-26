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

static void display_help(void)
{
    printf("\033[1mSCP-085\033[0m :\n");
    printf("    \033[3mWolf3d\033[0m is a '3D' game engine based on "
        "\033[3mraycasting.\033[0m\n");
    printf("    By \033[1mKevin HUYNH\033[0m &"
        " \033[1mHugo SORGUES\033[0m @ "
        "\033[34mEpitech\033[0m Marseille 2025\n");
    printf("\033[1mKeybinds\033[0m :\n"
        "   [\033[36mZ\033[0m] : Move forward\n"
        "   [\033[36mS\033[0m] : Move backward\n"
        "   [\033[36mQ\033[0m] : Strafe left\n"
        "   [\033[36mD\033[0m] : Strafe right\n"
        "   [\033[36mE\033[0m] : Look right\n"
        "   [\033[36mA\033[0m] : Look left\n"
        "   [\033[36mMouse\033[0m] : Look around\n"
        "   [\033[36mLeft Click\033[0m] : Use selected item\n"
        "   [\033[36mX\033[0m] : Interact with items\n"
        "   [\033[36mEscape\033[0m] : Pause the game\n"
    );
    printf("- Have fun \033[31m<3\033[0m\n");
}

int main(int argc, char **argv)
{
    if (argv[1]) {
        if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
            display_help();
            return (0);
        } else {
            fprintf(stderr, "Usage: %s [-h | --help]\n", argv[0]);
            return (84);
        }
    }
    srand(time(NULL));
    return wolf3d();
}
