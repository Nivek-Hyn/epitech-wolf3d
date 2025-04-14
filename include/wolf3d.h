/*
** EPITECH PROJECT, 2025
** bs_wolf3d
** File description:
** bs_wolf3d
*/

#ifndef WOLF_3D_
    #define WOLF_3D_

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <math.h>
    #include <time.h>
    #include <ctype.h>
    #include <errno.h>
    #include <float.h>
    #include <stdarg.h>

    #include <SFML/Graphics.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <SFML/System/Clock.h>

    #define PI 3.14159265358979323846
    #define STD_WIN_WIDTH 1920
    #define STD_WIN_HEIGHT 1080

    #define TILE_SIZE 64
    #define MAP_WIDTH 8
    #define MAP_HEIGHT 8

/////////////////////////////////
/// STRUCTS
/////////////////////////////////

typedef struct player_s {
    float x;
    float y;
    float angle;
} player_t;

typedef struct settings_s {
} settings_t;

typedef struct game_s {
    sfRenderWindow *render_window;
    sfEvent event;
    player_t *player;
    settings_t *settings;
} game_t;

/////////////////////////////////
/// GAME FUNCTIONS
/////////////////////////////////

////////////
// GAME
////////////
void game_loop(game_t *game);
////////////

////////////
// FREE FUNCTIONS
////////////
void free_game(game_t *game);
void free_player(player_t *player);
void free_settings(settings_t *settings);
////////////////////////

// STRUCT INIT
game_t *init_game_struct(void);
player_t *init_player(void);
settings_t *init_settings(void);
sfRenderWindow *init_window(void);

////////////
// EVENTS
////////////
void check_events(game_t *game);
// Window
void check_window_events(game_t *game);
void window_gained_focus(game_t *game);
void window_lost_focus(game_t *game);
void window_resized(game_t *game);
// Keyboard
void check_keyboard_inputs(game_t *game);
void keyboard_key_pressed(game_t *game);
void keyboard_key_released(game_t *game);
// Mouse
void check_mouse_inputs(game_t *game);
void mouse_button_pressed(game_t *game);
void mouse_button_released(game_t *game);
void mouse_moved(game_t *game);
void mouse_wheel_scrolled(game_t *game);
////////////

#endif /* !WOLF_3D_ */
