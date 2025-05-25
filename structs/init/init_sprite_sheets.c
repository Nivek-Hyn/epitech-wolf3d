/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues [WSL: Ubuntu]
** File description:
** init_sprite_sheets
*/

#include "wolf3d.h"

static void init_play_button(sprites_t *sprites)
{
    unsigned height_offset = 200;
    unsigned tile_count = 2;
    unsigned total_width = 900;
    unsigned tile_width = total_width / tile_count;

    sprites->btn_play = init_sprite_sheet(
        tile_count,
        sprite_create(
            "assets/textures/buttons/BTN_Play.png",
            1.0,
            (sfVector2f){
                (STD_WIN_WIDTH / 2) - ((total_width / tile_count) / 2),
                (STD_WIN_HEIGHT / 2) - ((total_width / tile_count) / 2)
                    + height_offset
            }
        ),
        create_int_rect(0, 0, 150, total_width / tile_count)
    );
}

static void init_settings_button(sprites_t *sprites)
{
    unsigned height_offset = 350;
    unsigned tile_count = 2;
    unsigned total_width = 900;
    unsigned tile_width = total_width / tile_count;

    sprites->btn_settings = init_sprite_sheet(
        tile_count,
        sprite_create(
            "assets/textures/buttons/BTN_Settings.png",
            1.0,
            (sfVector2f){
                (STD_WIN_WIDTH / 2) - ((total_width / tile_count) / 2),
                (STD_WIN_HEIGHT / 2) - ((total_width / tile_count) / 2)
                    + height_offset
            }
        ),
        create_int_rect(0, 0, 150, total_width / tile_count)
    );
}

static void init_quit_button(sprites_t *sprites)
{
    unsigned height_offset = 500;
    unsigned tile_count = 2;
    unsigned total_width = 900;
    unsigned tile_width = total_width / tile_count;

    sprites->btn_quit = init_sprite_sheet(
        tile_count,
        sprite_create(
            "assets/textures/buttons/BTN_Quit.png",
            1.0,
            (sfVector2f){
                (STD_WIN_WIDTH / 2) - ((total_width / tile_count) / 2),
                (STD_WIN_HEIGHT / 2) - ((total_width / tile_count) / 2)
                    + height_offset
            }
        ),
        create_int_rect(0, 0, 150, total_width / tile_count)
    );
}

static void init_return_button(sprites_t *sprites)
{
    unsigned height_offset = 550;
    unsigned width_offset = 650;
    unsigned tile_count = 2;
    unsigned total_width = 900;
    unsigned tile_width = total_width / tile_count;

    sprites->btn_return = init_sprite_sheet(
        tile_count,
        sprite_create(
            "assets/textures/buttons/BTN_Return.png",
            1.0,
            (sfVector2f){
                (STD_WIN_WIDTH / 2) - ((total_width / tile_count) / 2)
                    - width_offset,
                (STD_WIN_HEIGHT / 2) - ((total_width / tile_count) / 2)
                    + height_offset
            }
        ),
        create_int_rect(0, 0, 150, total_width / tile_count)
    );
}

static void init_window_change_button(sprites_t *sprites)
{
    unsigned height_offset = 55;
    unsigned width_offset = 300;
    unsigned tile_count = 4;
    unsigned total_width = 2400;
    unsigned tile_width = total_width / tile_count;

    sprites->btn_window_change = init_sprite_sheet(
        tile_count,
        sprite_create(
            "assets/textures/buttons/BTN_WindowChange.png",
            0.65,
            (sfVector2f){
                (STD_WIN_WIDTH / 2) - ((total_width / tile_count) / 2)
                    + width_offset,
                (STD_WIN_HEIGHT / 2) - ((total_width / tile_count) / 2)
                    - height_offset
            }
        ),
        create_int_rect(0, 0, 150, total_width / tile_count)
    );
}

void init_sprite_sheets(sprites_t *sprites)
{
    init_window_change_button(sprites);
    init_return_button(sprites);
    init_quit_button(sprites);
    init_settings_button(sprites);
    init_play_button(sprites);
    init_sfx_music_buttons(sprites);
}
