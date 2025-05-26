/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues [WSL: Ubuntu]
** File description:
** init_sprites
*/

#include "wolf3d.h"

static void init_ammo_icon(sprites_t *sprites,
    extra_data_t *extra_data)
{
    sprites->ammo_icon = sprite_create(
        "assets/textures/items/ammo.png",
        0.1,
        (sfVector2f){0, 0},
        extra_data
    );
}

static void init_main_menu_background(sprites_t *sprites,
    extra_data_t *extra_data)
{
    sprites->main_menu_background = sprite_create(
        "assets/textures/scp_background_blured.png",
        1.4,
        (sfVector2f){0, 0},
        extra_data
    );
}

static void init_scp_logo(sprites_t *sprites,
    extra_data_t *extra_data)
{
    sprites->scp_logo = sprite_create(
        "assets/textures/scp_logo.png",
        1.3,
        (sfVector2f){
            (STD_WIN_WIDTH / 2) - 200,
            (STD_WIN_HEIGHT / 2) - 450
        },
        extra_data
    );
}

static void init_scp_icon(sprites_t *sprites,
    extra_data_t *extra_data)
{
    sprites->scp_icon = sprite_create(
        "assets/textures/scp_icon.png",
        1.2,
        (sfVector2f){
            (STD_WIN_WIDTH / 2) - 575,
            (STD_WIN_HEIGHT / 2) - 440
        },
        extra_data
    );
}

static void init_cursor(sprites_t *sprites,
    extra_data_t *extra_data)
{
    sprites->cursor = sprite_create(
        "assets/textures/cursor.png",
        1.0,
        (sfVector2f){0, 0},
        extra_data
    );
}

static void init_window_mode_text(sprites_t *sprites,
    extra_data_t *extra_data)
{
    sprites->WindowMode_text = sprite_create(
        "assets/textures/WindowMode.png",
        0.5,
        (sfVector2f){
            (STD_WIN_WIDTH / 2) - 385,
            (STD_WIN_HEIGHT / 2) - 385
        },
        extra_data
    );
}

static void init_pause_menu_background(sprites_t *sprites,
    extra_data_t *extra_data)
{
    sprites->pause_menu_background = sprite_create(
        "assets/textures/PauseMenu.png",
        1.7,
        (sfVector2f){700, 100},
        extra_data
    );
}

static void init_pause_settings_button(sprites_t *sprites,
    extra_data_t *extra_data)
{
    unsigned height_offset = 255 + 15;
    unsigned tile_count = 2;
    unsigned total_width = 900;
    unsigned tile_width = total_width / tile_count;

    sprites->pause_btn_settings = init_sprite_sheet(
        tile_count,
        sprite_create(
            "assets/textures/buttons/BTN_Settings.png",
            1.0,
            (sfVector2f){
                (STD_WIN_WIDTH / 2) - ((total_width / tile_count) / 2),
                (STD_WIN_HEIGHT / 2) - ((total_width / tile_count) / 2)
                    + height_offset
            },
            extra_data
        ),
        create_int_rect(0, 0, 150, total_width / tile_count)
    );
}

static void init_pause_menu_button(sprites_t *sprites,
    extra_data_t *extra_data)
{
    unsigned height_offset = 400 + 15;
    unsigned tile_count = 2;
    unsigned total_width = 900;
    unsigned tile_width = total_width / tile_count;

    sprites->pause_btn_menu = init_sprite_sheet(
        tile_count,
        sprite_create(
            "assets/textures/buttons/BTN_Menu.png",
            1.0,
            (sfVector2f){
                (STD_WIN_WIDTH / 2) - ((total_width / tile_count) / 2),
                (STD_WIN_HEIGHT / 2) - ((total_width / tile_count) / 2)
                    + height_offset
            },
            extra_data
        ),
        create_int_rect(0, 0, 150, total_width / tile_count)
    );
}

sprites_t *init_sprites(extra_data_t *extra_data)
{
    sprites_t *sprites = malloc(sizeof(sprites_t));

    if (sprites == NULL)
        return NULL;
    init_sprite_sheets(sprites, extra_data);
    init_cursor(sprites, extra_data);
    init_scp_logo(sprites, extra_data);
    init_scp_icon(sprites, extra_data);
    init_window_mode_text(sprites, extra_data);
    init_main_menu_background(sprites, extra_data);
    init_ammo_icon(sprites, extra_data);
    init_pause_menu_background(sprites, extra_data);
    init_pause_settings_button(sprites, extra_data);
    init_pause_menu_button(sprites, extra_data);
    init_pause_save_button(sprites, extra_data);
    init_pause_load_button(sprites, extra_data);
    return sprites;
}
