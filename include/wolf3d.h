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
    #include <string.h>

    #include <SFML/Graphics.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <SFML/System/Clock.h>

    /* ASSETS */
    #define DEFAULT_FONT "assets/fonts/BAUHAUS DEMI.OTF"
    #define ARIAL_FONT "assets/fonts/ARIAL.TTF"

    /* SAVE */
    #define SAVE_FILE "save.txt"
    #define ITEM_SAVE_FILE "item_save.txt"

    /* TRIGONOMETRY */
    #define PI 3.14159265358979323846
    #define UNIT_LIMIT 2 * PI
    #define PI2 PI / 2
    #define PI3 3 * PI / 2
    #define RAD_OFFSET 0.0174533

    /* WINDOW MACROS */
    #define STD_FPS 60
    #define STD_WIN_WIDTH 1920
    #define STD_WIN_HEIGHT 1080
    #define STD_WIN_TITLE "Wolf3D - SCP-084"

    /* COLORS */
    #define HEXA_COLOR_LIMIT 255

    /* RAYCAST TMP WINDOW - TEMPORARY !!!!!!!*/
    #define RAY_OFFSET_X 700
    #define RAY_OFFSET_Y 300
    #define RAYCAST_WIN_HEIGHT 540
    #define RAYCAST_WIN_WITDH 960
    #define RAYCAST_WIN_X_CENTER RAY_OFFSET_X + RAYCAST_WIN_WITDH / 2
    #define RAYCAST_WIN_Y_CENTER RAY_OFFSET_Y + RAYCAST_WIN_HEIGHT / 2
    #define RAYCAST_WIN_CENTER RAYCAST_WIN_X_CENTER, RAYCAST_WIN_Y_CENTER
    #define RAYCAST_JUMP 6

    /* Player settings */
    #define MOVE_SPEED 2
    #define PLAYER_RADIUS 10
    #define STD_LOOK_SPEED 3
    #define MOUSE_SENSITIVITY 0.01
    #define SIGHT_LINE 100000
    #define STD_FOV 70
    #define INTERACTION_RANGE 50

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
    #define WALL_BRIGHTNESS 0.3f

    /* Music & Sounds */
    #define MUSIC_PLAY 0
    #define MUSIC_STOP 1

    /* Tile parameters */
    #define TILE_SIZE 64
    #define NB_WALL_TYPES 2
    #define NB_FLOOR_TYPES 2
    #define NB_CEILING_TYPES 2

    /* Interactions Settings */
    #define INTERACTION_TEXT_Y_OFFSET 100

    /* Item settings */
    #define ITEM_RADIUS 5
    #define MAX_WORLD_ITEMS 100
    #define ITEM_TYPE_COUNT 4
    #define WORLD_ITEM_DRAW_SIZE 10
    #define WORLD_ITEM_MAX_DRAW_SIZE 300

    /* Inventory Settings */
    #define INVENTORY_SIZE 5
    #define INVENTORY_Y_OFFSET 100
    #define INVENTORY_SLOT_SIZE 100
    #define INVENTORY_SLOT_SPACING 25
    #define INVENTORY_SLOT_SELECTED_SCALE 1.2f
    #define INVENTORY_SLOT_BACKGROUND_COLOR 0, 0, 0, 128
    #define INVENTORY_SLOT_BORDER_COLOR sfColor_fromRGB(50, 50, 50)
    #define INVENTORY_SLOT_OUTLINE_THICKNESS 2.0f

    /* Flashlight settings */
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

typedef struct extra_data_s {
    float ray_distances[RAYCAST_WIN_WITDH];
} extra_data_t;

typedef struct {
    sfVector2f pos;
    float dx;
    float dy;
    float distance;
    float angle_to_sprite;
    float relative_angle;
    float proj_plane_dist;
    float sprite_screen_x;
    int screen_x;
    int sprite_screen_size;
    // Config Rect
    int draw_start_x;
    int draw_end_x;
    int visible_start;
    int visible_end;
    int first_visible_col;
    int last_visible_col;
    sfVector2u tex_size;
    int tex_x_start;
    int tex_x_end;
    int tex_width;
    // Size
    float scale;
    float factor;
    // Color
    sfUint8 alpha;
    sfUint8 shade;
    sfColor color;
} world_item_draw_vars_t;

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

typedef struct item_key_s {
    int id;
} item_key_t;

typedef struct gun_s {
    int ammo;
} gun_t;

typedef struct flashlight_s {
    bool is_on;
    float battery;
} flashlight_t;

typedef enum item_type_e {
    ITEM_NONE,
    ITEM_KEY,
    ITEM_FLASHLIGHT,
    ITEM_GUN
} item_type_t;

typedef struct item_s {
    item_type_t type;
    int quantity;
    sfTexture *texture;
    sfImage *image;
    void *data;
} item_t;

typedef struct world_item_s {
    item_t item;
    sfVector2f position;
    sfSprite *sprite;
    sfIntRect sprite_rect;
    sfCircleShape *circle_visual;
    bool is_visible;
    bool can_interact;
} world_item_t;

typedef struct item_manager_s {
    world_item_t world_items[MAX_WORLD_ITEMS];
    int world_item_count;
} item_manager_t;

typedef struct inventory_s {
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
    bool can_interact;
    bool interact;
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

typedef struct text_list_s {
    sfText *inventory_full;
    sfText *press_x_to_interact;
} text_list_t;

typedef struct sprite_sheet_s {
    sfSprite *sprite;
    sfIntRect *int_rect;
    int tile_count;
} sprite_sheet_t;

typedef struct sprites_s {
    sfSprite *cursor;
    sprite_sheet_t *btn_play;
    sprite_sheet_t *btn_settings;
    sprite_sheet_t *btn_quit;
    sprite_sheet_t *btn_return;
    sprite_sheet_t *btn_window_change;
    sfSprite *main_menu_background;
    sfSprite *scp_logo;
    sfSprite *scp_icon;
    sfSprite *WindowMode_text;
    sprite_sheet_t *sfx_status;
    sprite_sheet_t *music_status;
    sfSprite *sfx_icon;
    sfSprite *music_icon;
    sfSprite *pause_menu_background;
    sprite_sheet_t *pause_btn_settings;
    sprite_sheet_t *pause_btn_menu;
    sprite_sheet_t *pause_btn_save;
    sprite_sheet_t *pause_btn_load;
} sprites_t;

typedef enum scene_e {
    GAME = 1,
    MENU_MAIN = 2,
    MENU_SETTINGS = 3,
    MENU_CREDITS = 4,
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
    text_list_t *texts;
    item_manager_t *item_manager;
    bool is_paused;
    // Menus
    sfClock *settings_cooldown;
    sfClock *sfx_cooldown;
    scene_t current_scene;
    scene_t precedent_scene;
    sprites_t *sprites;
    sfx_t *sounds;
    // Extra
    extra_data_t *extra_data;
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
// INTERACTIONS
void check_interactions(game_t *game);
void draw_interaction_message(game_t *game);
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
void draw_inventory_full_message(game_t *game, int trigger);
// FLASHLIGHT
void turn_flashlight(game_t *game);
// ITEMS
void draw_items(game_t *game);
bool spawn_item(item_manager_t *manager, item_t item, sfVector2f pos);
void despawn_item(item_manager_t *manager, int index);
bool pickup_item(player_t *player, item_manager_t *manager, int index);
bool drop_inventory_item(player_t *player, item_manager_t *manager, int slot);
void reset_world_item(world_item_t *item);
void reset_inventory_slot(inventory_t *inventory, int slot_index);
void draw_selected_item_data(game_t *game);
void draw_world_items(game_t *game);
void use_selected_item(game_t *game, inventory_t *inventory);
// INVENTORY
void draw_inventory(game_t *game, inventory_t *inventory);
void inventory_select_next_slot(inventory_t *inventory);
void inventory_select_previous_slot(inventory_t *inventory);
// FLASHLIGHT
void turn_flashlight(game_t *game);
void update_player_flashlight_battery(game_t *game);
void draw_flashlight_battery(game_t *game, flashlight_t *flashlight);
void draw_flashlight_battery(game_t *game, flashlight_t *flashlight);
// SAVE & LOAD
int load_map_file(const char *filename, world_t *world);
void load_item_save_file(const char *filename, item_manager_t *manager);
////////////

////////////
// MENUS
////////////
void main_menu_loop(game_t *game);
void draw_buttons(game_t *game);
void draw_main_menu_background(game_t *game);
void check_main_menu_buttons_events(game_t *game);
void check_play_button_events(game_t *game);
void check_settings_button_events(game_t *game);
void check_quit_button_events(game_t *game);
// SETTINGS
void settings_menu_loop(game_t *game);
void check_settings_buttons_events(game_t *game);
void check_return_button_events(game_t *game);
void draw_settings_buttons(game_t *game);
void check_window_change_button_events(game_t *game);
void check_sfx_button_events(game_t *game);
void check_music_button_events(game_t *game);
// PAUSE
void pause_event(game_t *game);
void update_paused_buttons(game_t *game);
void draw_paused_menu(game_t *game);
void check_paused_settings_button_events(game_t *game);
void check_paused_menu_button_events(game_t *game);
void check_paused_load_button_events(game_t *game);
void check_paused_save_button_events(game_t *game);
void init_pause_save_button(sprites_t *sprites);
void init_pause_load_button(sprites_t *sprites);
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
text_list_t *init_texts(font_list_t *fonts);
item_manager_t *init_item_manager(void);
map_t **init_standard_map(int map_size_x, int map_size_y);
void init_map_textures(world_t *world);
void init_map_images(world_t *world);
scene_t init_scene_enum(void);
sprites_t *init_sprites(void);
sfx_t *init_sfx(settings_t *settings);
void init_sprite_sheets(sprites_t *sprites);
extra_data_t *init_extra_data(void);
void init_sfx_music_buttons(sprites_t *sprites);
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
void init_changed_render_window(game_t *game);
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
sfText *create_text(char *string, int size,
    sfColor color, sfVector2f position);
sfText *create_centered_text(char *str, int size,
    sfFont *font, sfVector2f position);
void draw_text(game_t *game, const char *str, int size, sfVector2f pos);
bool is_position_within_map(world_t *world, float px, float py);
bool is_position_an_empty_space(world_t *world, float px, float py);
bool is_cursor_above_sprite(sfSprite *sprite, sfRenderWindow *render_window);
item_t *inventory_slot(inventory_t *inventory, int slot);
item_t *inventory_selected_slot(inventory_t *inventory);
void *inventory_slot_data(inventory_t *inventory, int slot);
void *inventory_selected_slot_data(inventory_t *inventory);
flashlight_t *get_flashlight(inventory_t *inventory);
void give_flashlight(inventory_t *inventory, int slot);
item_t create_item(int type);
sfTexture *create_texture_from_item_type(int type);
sfImage *create_image_from_item_type(int type);
void *create_data_from_item_type(int type);
char *my_revstr(char *str);
int nbr_of_digits(int nb);
char *nbr_to_str(int nb);
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
void free_texts(text_list_t *texts);
void free_item_manager(item_manager_t *item_manager);
void free_sprite_sheet(sprite_sheet_t *sprite_sheet);
void free_sprites(game_t *game);
void free_sfx(sfx_t *sfx);
void free_extra_data(extra_data_t *extra_data);
////////////

////////////
// ARRAYS
////////////
int **alloc_int_matrix(int y, int x);
void free_int_matrix(int **matrix, int y);
////////////

#endif /* WOLF_3D_ */
