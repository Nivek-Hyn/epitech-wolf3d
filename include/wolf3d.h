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
    #include <stdbool.h>
    #include <unistd.h>
    #include <fcntl.h>

    #include <SFML/Graphics.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <SFML/System/Clock.h>

    #define PI 3.14159265358979323846

    /* WINDOW MACROS */
    #define STD_WIN_WIDTH 1920
    #define STD_WIN_HEIGHT 1080
    /* Window settings */
    #define WINDOWED 0
    #define FULL_SCREEN 1

    /* Player settings */
    #define MOVE_INCREMENTS 5
    /* World settings */
    #define STD_MATRIX_Y 10
    #define STD_MATRIX_X 15

    /* Music & Sounds */
    #define MUSIC_PLAY 0
    #define MUSIC_STOP 1

    /* Tile parameters */
    #define TILE_SIZE 64

/////////////////////////////////////////
/// STRUCTS
/////////////////////////////////////////

typedef struct world_s {
    int **matrix;
    int matrix_size_x;
    int matrix_size_y;
} world_t;

typedef struct player_s {
    float x;
    float y;
    float angle;
    sfCircleShape *player_visual;
} player_t;

typedef struct settings_s {
    int window_mode;
} settings_t;

typedef struct game_s {
    sfRenderWindow *render_window;
    sfEvent event;
    player_t *player;
    world_t *world;
    settings_t *settings;
} game_t;

/////////////////////////////////////////
/// GAME FUNCTIONS
/////////////////////////////////////////

////////////
// GAME
////////////
void game_loop(game_t *game);
////////////

////////////
// SHAPES
////////////
// Circles
sfCircleShape *create_circle(sfVector2f position, float radius,
    sfColor outline_color, sfColor fill_color);
void set_circle_position(sfCircleShape *shape, sfVector2f position);
sfBool are_circles_intersecting(sfCircleShape *c1, sfCircleShape *c2);
////////////

////////////
// SPRITES
////////////
sfSprite *sprite_create(char *filepath, float scale, sfVector2f position);
sfIntRect *intrect_create(int top, int left, int height, int width);
////////////

////////////
// FREE FUNCTIONS
////////////
void free_game(game_t *game);
void free_player(player_t *player);
void free_settings(settings_t *settings);
////////////////////////

////////////
// STRUCT INIT
////////////
game_t *init_game_struct(void);
player_t *init_player(void);
settings_t *init_settings(void);
sfRenderWindow *init_window(void);
world_t *world_init(void);
////////////

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

////////////
// MAP
////////////
// Matrix functions
int **blank_matrix_create(int matrix_size_x, int matrix_size_y);
int **rand_matrix_create(int matrix_size_x, int matrix_size_y);
void matrix_display(int **matrix, int matrix_size_x, int matrix_size_y);
////////////

#endif /* !WOLF_3D_ */
