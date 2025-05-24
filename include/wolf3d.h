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

    /* Map settings */
    #define MAP_X 0
    #define MAP_Y 0
    #define WALL_MAP_OUTLINE_COLOR 0, 200, 0, 255
    #define WALL_MAP_COLOR sfWhite
    #define FLOOR_MAP_OUTLINE_COLOR 0, 0, 200, 255
    #define FLOOR_MAP_COLOR sfWhite
    #define CEILING_MAP_OUTLINE_COLOR 200, 0, 0, 255
    #define CEILING_MAP_COLOR sfWhite

    /* Music & Sounds */
    #define MUSIC_PLAY 0
    #define MUSIC_STOP 1

    /* Tile parameters */
    #define TILE_SIZE 64
    #define NB_WALL_TYPES 2
    #define NB_FLOOR_TYPES 2
    #define NB_CEILING_TYPES 2

    /* Item settings */
    #define ITEM_RADIUS 5
    #define MAX_WORLD_ITEMS 100
    #define ITEM_TYPE_COUNT 4

    /* Inventory Settings */
    #define INVENTORY_SIZE 5
    #define INVENTORY_Y_OFFSET 100
    #define INVENTORY_SLOT_SIZE 100
    #define INVENTORY_SLOT_SPACING 25
    #define INVENTORY_SLOT_SELECTED_SCALE 1.2f
    #define INVENTORY_SLOT_BACKGROUND_COLOR 0, 0, 0, 128
    #define INVENTORY_SLOT_BORDER_COLOR sfColor_fromRGB(50, 50, 50)
    #define INVENTORY_SLOT_OUTLINE_THICKNESS 2.0f

    /* Flaslight settings */
    #define FLASHLIGHT_RADIUS 500
    #define MAX_FLASHLIGHT_BATTERY 100.0f
    #define FLASHLIGHT_BATTERY_DECREASE 1
    #define MAX_BATTERY_WIDTH 100.0f

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

typedef struct flashlight_s {
    bool is_on;
    float battery;
} flashlight_t;

typedef enum item_type_e {
    ITEM_NONE,
    ITEM_KEY,
    ITEM_FLASHLIGHT,
    ITEM_WEAPON
} item_type_t;

typedef struct {
    item_type_t type;
    int quantity;
    sfTexture *texture;
    void *data;
} item_t;

typedef struct {
    item_t item;
    sfVector2f position;
    sfSprite *sprite;
    sfCircleShape *circle_visual;
} world_item_t;

typedef struct item_manager_s {
    world_item_t world_items[MAX_WORLD_ITEMS];
    int world_item_count;
} item_manager_t;

typedef struct {
    item_t slots[INVENTORY_SIZE];
    int selected_slot;
    float slot_scales[INVENTORY_SIZE];
} inventory_t;

typedef struct player_s {
    float x;
    float y;
    float delta_x;
    float delta_y;
    float angle;
    sfCircleShape *player_visual;
    inventory_t *inventory;
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
} settings_t;

typedef struct map_s {
    wall_tile_t wall_type;
    sfRectangleShape *wall_rectangle;
    floor_tile_t floor_type;
    sfRectangleShape *floor_rectangle;
    ceiling_tile_t ceiling_type;
    sfRectangleShape *ceiling_rectangle;
} map_t;

typedef struct world_s {
    map_t **map;
    int map_size_x;
    int map_size_y;
    sfTexture *wall_textures[NB_WALL_TYPES];
    sfTexture *floor_textures[NB_FLOOR_TYPES];
    sfTexture *ceiling_textures[NB_CEILING_TYPES];
    sfImage *floor_images[NB_FLOOR_TYPES];
    sfImage *ceiling_images[NB_CEILING_TYPES];
} world_t;

typedef struct game_time_s {
    sfClock *clock;
    float delta_time;
} game_time_t;

typedef struct font_list_s {
    sfFont *normal;
    sfFont *arial;
} font_list_t;

typedef struct game_s {
    sfRenderWindow *render_window;
    sfEvent event;
    player_t *player;
    world_t *world;
    settings_t *settings;
    keys_t *keys;
    mouse_t *mouse;
    game_time_t *time;
    font_list_t *fonts;
    item_manager_t *item_manager;
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
// ITEMS
void draw_items(game_t *game);
bool spawn_item(item_manager_t *manager, item_t item, sfVector2f pos);
void despawn_item(item_manager_t *manager, int index);
bool pickup_item(player_t *player, item_manager_t *manager, int index);
bool drop_inventory_item(player_t *player, item_manager_t *manager, int slot);
void reset_world_item(world_item_t *item);
void reset_inventory_slot(inventory_t *inventory, int slot_index);
void draw_selected_item_data(game_t *game);
// INVENTORY
void draw_inventory(game_t *game, inventory_t *inventory);
void inventory_select_next_slot(inventory_t *inventory);
void inventory_select_previous_slot(inventory_t *inventory);
// FLASHLIGHT
void turn_flashlight(game_t *game);
void update_player_flashlight_battery(game_t *game);
void draw_flashlight_battery(game_t *game, flashlight_t *flashlight);
// SAVE & LOAD
int load_map_file(const char *filename, world_t *world);
void load_item_save_file(const char *filename, item_manager_t *manager);
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
game_time_t *init_time(void);
font_list_t *init_fonts(void);
item_manager_t *init_item_manager(void);
map_t **init_standard_map(int map_size_x, int map_size_y);
void init_map_textures(world_t *world);
void init_map_images(world_t *world);
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
// UTILITY FUNCTIONS
////////////
bool is_position_within_map(world_t *world, float px, float py);
bool is_position_an_empty_space(world_t *world, float px, float py);
bool is_cursor_above_sprite(sfSprite *sprite, sfRenderWindow *render_window);
item_t *inventory_slot(inventory_t *inventory, int slot);
item_t *inventory_selected_slot(inventory_t *inventory);
void *inventory_slot_data(inventory_t *inventory, int slot);
void *inventory_selected_slot_data(inventory_t *inventory);
flashlight_t *get_flashlight(inventory_t *inventory);
void give_flashlight(inventory_t *inventory, int slot);
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
void free_item_manager(item_manager_t *item_manager);
////////////

////////////
// ARRAYS
////////////
int **alloc_int_matrix(int y, int x);
void free_int_matrix(int **matrix, int y);
////////////

#endif /* !WOLF_3D_ */
