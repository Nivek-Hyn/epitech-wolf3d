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
    #define MOVE_SPEED 3
    #define PLAYER_RADIUS 10
    #define STD_LOOK_SPEED 3
    #define MOUSE_SENSITIVITY 0.01
    #define SIGHT_LINE 100000
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

typedef enum tile_e {
    EMPTY = 0,
    WALL = 1,
} tile_t;

typedef struct keys_s {
    int z;
    int q;
    int s;
    int d;
    int a;
    int e;
} keys_t;

typedef struct player_s {
    float x;
    float y;
    float delta_x;
    float delta_y;
    float angle;
    sfCircleShape *player_visual;
} player_t;

typedef struct mouse_s {
    int delta_x;
    float sensivity;
    sfVector2i previous_position;
    bool is_locked;
} mouse_t;

typedef struct settings_s {
    int window_mode;
} settings_t;

typedef struct map_s {
    tile_t type;
    sfRectangleShape *rectangle;
} map_t;

typedef struct world_s {
    map_t **map;
    int map_size_x;
    int map_size_y;
} world_t;

typedef struct game_s {
    sfRenderWindow *render_window;
    sfEvent event;
    player_t *player;
    world_t *world;
    settings_t *settings;
    keys_t *keys;
    mouse_t *mouse;
} game_t;

/////////////////////////////////////////
/// GAME FUNCTIONS
/////////////////////////////////////////

////////////
// GAME
////////////
void game_loop(game_t *game);
// PLAYER
void draw_player(game_t *game);
void update_player(game_t *game);
void player_look_left(game_t *game, float look_speed);
void player_look_right(game_t *game, float look_speed);
////////////

////////////
// SHAPES
////////////
// Circles
sfCircleShape *create_circle(sfVector2f position, float radius,
    sfColor outline_color, sfColor fill_color);
void set_circle_position(sfCircleShape *shape, sfVector2f position);
sfBool are_circles_intersecting(sfCircleShape *c1, sfCircleShape *c2);
// Rectangles
sfRectangleShape *create_rectangle(sfVector2f position, sfVector2f size,
    sfColor outline_color, sfColor fill_color);
////////////

////////////
// SPRITES
////////////
sfSprite *sprite_create(char *filepath, float scale, sfVector2f position);
sfIntRect *intrect_create(int top, int left, int height, int width);
////////////

////////////
// STRUCT INIT
////////////
game_t *init_game_struct(void);
player_t *init_player(void);
settings_t *init_settings(void);
sfRenderWindow *init_window(void);
world_t *init_world(void);
keys_t *init_keys(void);
mouse_t *init_mouse(void);
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
// MOUSE & CURSOR
////////////
void mouse_update_lock_status(game_t *game);
void mouse_mid_locked(game_t *game);
void update_mouse(game_t *game);

////////////
// MAP
////////////
void draw_map_line(game_t *game, int *map_x, int *map_y, int y);
void draw_map(game_t *game);
// Matrix functions
int **blank_matrix_create(int map_size_x, int map_size_y);
int **rand_matrix_create(int map_size_x, int map_size_y);
void matrix_display(int **map, int map_size_x, int map_size_y);
////////////

////////////
// FREE FUNCTIONS
////////////
void free_game(game_t *game);
void free_player(player_t *player);
void free_map(map_t **map, int map_size_x, int map_size_y);
void free_tile(map_t **map, int x, int y);
void free_settings(settings_t *settings);
void free_world(world_t *world);
void free_keys(keys_t *keys);
void free_mouse(mouse_t *mouse);
////////////

#endif /* !WOLF_3D_ */
