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
    #define UNIT_LIMIT 2 * PI
    #define PI2 PI / 2
    #define PI3 3 * PI / 2
    #define RAD_OFFSET 0.0174533 / 2

    /* WINDOW MACROS */
    #define STD_WIN_WIDTH 1920
    #define STD_WIN_HEIGHT 1080

    #define RAYCAST_OFFSET_X 640
    #define RAYCAST_JUMP 6
    #define RAYCAST_WIN_HEIGHT 1080 / 2
    #define RAYCAST_WIN_WITDH 1920 / 2

    /* Window settings */
    #define WINDOWED 0
    #define FULL_SCREEN 1

    /* Player settings */
    #define MOVE_SPEED 2
    #define PLAYER_RADIUS 10
    #define STD_LOOK_SPEED 3
    #define MOUSE_SENSITIVITY 0.01
    #define SIGHT_LINE 100000
    #define STD_FOV 70

    /* World settings */
    #define STD_MATRIX_Y 10
    #define STD_MATRIX_X 15
    #define STD_DOF 16

    /* Music & Sounds */
    #define MUSIC_PLAY 0
    #define MUSIC_STOP 1

    /* Tile parameters */
    #define TILE_SIZE 64

/////////////////////////////////////////
/// STRUCTS
/////////////////////////////////////////

typedef struct raycast_values_s {
    int r;
    int map_x;
    int map_y;
    int map_position;
    int depth_of_field;
    float ray_x;
    float ray_y;
    float ray_angle;
    float x_offset;
    float y_offset;
    // Horizontal
    float horizontal_dist;
    float horizontal_x;
    float horizontal_y;
    // Vertical
    float vertical_dist;
    float vertical_x;
    float vertical_y;
    // Global
    float total_dist;
} raycast_values_t;

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
    float field_of_view;
    int ray_count;
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
// COLLISION:
int check_player_walls_collision(float player_pos_x, float player_pos_y,
    game_t *game);
int compare_lines_to_player(game_t *game, float player_pos_x,
    float player_pos_y, int y);
int check_circle_rectangle_collision(float circle_pos_x, float circle_pos_y,
    float circle_radius, sfRectangleShape *rectangle);
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
raycast_values_t *init_raycast_values(void);
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

////////////
// MAP
////////////
void draw_map(game_t *game);
// Matrix functions
int **blank_matrix_create(int map_size_x, int map_size_y);
int **rand_matrix_create(int map_size_x, int map_size_y);
void matrix_display(int **map, int map_size_x, int map_size_y);
////////////

////////////
// RAYCASTING
////////////
void raycast(game_t *game);
void draw_std_line(sfRenderWindow *render_win, sfVertex vert1, sfVertex vert2);
float player_to_ray_distance(player_t *player,
    float ray_x, float ray_y, float angle);
void draw_ray(game_t *game, raycast_values_t *var);
void set_ray_distance(raycast_values_t *var);
void set_ray_angle_limit(raycast_values_t *var);
void draw_3d_walls(game_t *game, raycast_values_t *var);
// HORIZONTAL
void horizontal_raycast(game_t *game, raycast_values_t *var);
void draw_horizontal_ray(game_t *game, raycast_values_t *var);
void horizontal_ray_straight(game_t *game, raycast_values_t *var);
void horizontal_ray_up(game_t *game, raycast_values_t *var, float atan);
void horizontal_ray_down(game_t *game, raycast_values_t *var, float atan);
// VERTICAL
void vertical_raycast(game_t *game, raycast_values_t *var);
void draw_vertical_ray(game_t *game, raycast_values_t *var);
void vertical_ray_straight(game_t *game, raycast_values_t *var);
void vertical_ray_left(game_t *game, raycast_values_t *var, float atan);
void vertical_ray_right(game_t *game, raycast_values_t *var, float atan);
// TRIGO
float limit_trigo_angle(float angle);
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
void free_raycast_values(raycast_values_t *values);
////////////

#endif /* !WOLF_3D_ */
