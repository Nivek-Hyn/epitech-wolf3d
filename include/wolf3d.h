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
    #define RAD_OFFSET 0.0174533

    /* WINDOW MACROS */
    #define STD_FPS 60
    #define STD_WIN_WIDTH 1920
    #define STD_WIN_HEIGHT 1080

    /* COLORS */
    #define HEXA_COLOR_LIMIT 255

    /* RAYCAST TMP WINDOW - TEMPORARY !!!!!!!*/
    #define RAY_OFFSET_X 700
    #define RAY_OFFSET_Y 300
    #define RAYCAST_WIN_HEIGHT 540
    #define RAYCAST_WIN_WITDH 960
    #define RAYCAST_JUMP 6

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
    #define NB_WALL_TYPES 2
    #define NB_FLOOR_TYPES 2
    #define NB_CEILING_TYPES 2

    /* Tool settings */
    #define FLASHLIGHT_RADIUS 500
    #define MAX_FLASHLIGHT_BATTERY 100.0f
    #define FLASHLIGHT_BATTERY_DECREASE 1
    #define MAX_BATTERY_WIDTH 100.0f

    /* SFX & Music */
    #define SFX_VOLUME 50
    #define MUSIC_VOLUME 20

/////////////////////////////////////////
/// STRUCTS
/////////////////////////////////////////

typedef struct raycast_values_s {
    int drawn_rays;
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

typedef enum wall_tile_e {
    EMPTY_WALL = 0,
    WALL = 1,
} wall_tile_t;

typedef enum floor_tile_e {
    EMPTY_FLOOR = 0,
    FLOOR = 1,
} floor_tile_t;

typedef enum ceiling_tile_e {
    EMPTY_CEILING = 0,
    CEILING = 1,
} ceiling_tile_t;

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
    bool flashlight;
    float flashlight_battery;
} player_t;

typedef struct mouse_s {
    int delta_x;
    float sensivity;
    sfVector2i previous_position;
    bool is_locked;
} mouse_t;

// Window Settings
typedef enum window_settings_e {
    FULLSCREEN = 0,
    WINDOWED = 1,
} window_settings_t;

typedef struct settings_s {
    enum window_settings_e window_mode;
    int window_width;
    int window_height;
    float fov;
    int ray_count;
    // SFX - Music
    int sfx_volume;
    int music_volume;
    bool sfx_mute;
    bool music_mute;
} settings_t;

typedef struct map_s {
    wall_tile_t wall_type;
    sfRectangleShape *wall_rectangle;
    sfTexture *wall_texture;
    floor_tile_t floor_type;
    sfRectangleShape *floor_rectangle;
    sfTexture *floor_texture;
    ceiling_tile_t ceiling_type;
    sfTexture *ceiling_texture;
    sfRectangleShape *ceiling_rectangle;
} map_t;

typedef struct world_s {
    map_t **map;
    int map_size_x;
    int map_size_y;
    sfTexture *wall_textures[NB_WALL_TYPES];
    sfTexture *floor_textures[NB_FLOOR_TYPES];
    sfTexture *ceiling_textures[NB_CEILING_TYPES];
} world_t;

typedef struct game_time_s {
    sfClock *clock;
    float delta_time;
} game_time_t;

typedef struct font_list_s {
    sfFont *normal;
    sfFont *arial;
} font_list_t;

typedef struct sprite_sheet_s {
    sfSprite *sprite;
    sfIntRect *int_rect;
    int tile_count;
} sprite_sheet_t;

typedef struct sprites_s {
    sprite_sheet_t *btn_play;
    sprite_sheet_t *btn_settings;
    sprite_sheet_t *btn_quit;
    sfSprite *main_menu_background;
} sprites_t;

typedef enum scene_e {
    GAME = 1,
    MENU_MAIN = 2,
} scene_t;

typedef struct sfx_s {
    sfMusic *menu_music;
    // Button sounds
    sfSound *button_hover;
    sfSoundBuffer *button_hover_buffer;
    sfSound *button_click;
    sfSoundBuffer *button_click_buffer;
} sfx_t;

typedef struct game_s {
    // CSFML
    sfRenderWindow *render_window;
    sfEvent event;
    // Gameplay
    player_t *player;
    world_t *world;
    settings_t *settings;
    keys_t *keys;
    mouse_t *mouse;
    game_time_t *time;
    font_list_t *fonts;
    // Menus
    scene_t current_scene;
    sprites_t *sprites;
    sfx_t *sounds;
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
// COLLISION
int check_player_walls_collision(float player_pos_x, float player_pos_y,
    game_t *game);
int compare_lines_to_player(game_t *game, float player_pos_x,
    float player_pos_y, int y);
int check_circle_rectangle_collision(float circle_pos_x, float circle_pos_y,
    float circle_radius, sfRectangleShape *rectangle);
// BATTERY
void update_player_flashlight_battery(game_t *game);
void draw_battery(game_t *game);
// SAVE & LOAD
void load_map_file(const char *filename, world_t *world);
////////////

////////////
// MENUS
////////////
void main_menu_loop(game_t *game);
void draw_buttons(game_t *game);
void draw_main_menu_background_image(game_t *game);
void check_buttons_events(game_t *game);
void check_play_button_events(game_t *game);
void check_settings_button_events(game_t *game);
void check_quit_button_events(game_t *game);
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
bool is_cursor_above_sprite(sfSprite *sprite, sfRenderWindow *render_window);
sprite_sheet_t *init_sprite_sheet(int tile_count,
    sfSprite *sprite, sfIntRect *int_rect);
sfIntRect *create_int_rect(int top, int left, int height, int width);
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
game_time_t *init_time(void);
font_list_t *init_fonts(void);
scene_t init_scene_enum(void);
sprites_t *init_sprites(void);
sfx_t *init_sfx(settings_t *settings);
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
// DRAW
void draw_3d_walls(game_t *game, raycast_values_t *var);
void draw_wall_line(game_t *game, raycast_values_t *var,
    float line_height, float line_offset);
void draw_wall_rectangle(game_t *game, raycast_values_t *var,
    float line_height, float line_offset);
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
float rad(float degree);
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
void free_time(game_time_t *time);
void free_fonts(font_list_t *fonts);
void free_sprite_sheet(sprite_sheet_t *sprite_sheet);
void free_sprites(game_t *game);
void free_sfx(sfx_t *sfx);
////////////

////////////
// ARRAYS
////////////
int **alloc_int_matrix(int y, int x);
void free_int_matrix(int **matrix, int y);
////////////

#endif /* WOLF_3D_ */
