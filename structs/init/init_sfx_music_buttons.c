/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues [WSL: Ubuntu]
** File description:
** init_sfx_music_buttons
*/

#include "wolf3d.h"

static void init_sfx_icon(sprites_t *sprites,
    extra_data_t *extra_data)
{
    sprites->sfx_icon = sprite_create(
        "assets/textures/SFXIcon.png",
        1.1,
        (sfVector2f){
            (STD_WIN_WIDTH / 2) - 350,
            (STD_WIN_HEIGHT / 2) - 150
        }, extra_data
    );
}

static void init_music_icon(sprites_t *sprites,
    extra_data_t *extra_data)
{
    sprites->music_icon = sprite_create(
        "assets/textures/MusicIcon.png",
        1.1,
        (sfVector2f){
            (STD_WIN_WIDTH / 2) - 350,
            (STD_WIN_HEIGHT / 2)
        }, extra_data
    );
}

static void init_window_change_button(sprites_t *sprites,
    extra_data_t *extra_data)
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
            }, extra_data
        ),
        create_int_rect(0, 0, 150, total_width / tile_count)
    );
}

static void init_music_status(sprites_t *sprites,
    extra_data_t *extra_data)
{
    unsigned height_offset = 310;
    unsigned width_offset = 300;
    unsigned tile_count = 4;
    unsigned total_width = 2400;
    unsigned tile_width = total_width / tile_count;

    sprites->music_status = init_sprite_sheet(
        tile_count,
        sprite_create(
            "assets/textures/buttons/BTN_MuteUnmute.png",
            0.65,
            (sfVector2f){
                (STD_WIN_WIDTH / 2) - ((total_width / tile_count) / 2)
                    + width_offset,
                (STD_WIN_HEIGHT / 2) - ((total_width / tile_count) / 2)
                    + height_offset
            }, extra_data
        ),
        create_int_rect(0, 0, 150, total_width / tile_count)
    );
}

static void init_sfx_status(sprites_t *sprites,
    extra_data_t *extra_data)
{
    unsigned height_offset = 160;
    unsigned width_offset = 300;
    unsigned tile_count = 4;
    unsigned total_width = 2400;
    unsigned tile_width = total_width / tile_count;

    sprites->sfx_status = init_sprite_sheet(
        tile_count,
        sprite_create(
            "assets/textures/buttons/BTN_MuteUnmute.png",
            0.65,
            (sfVector2f){
                (STD_WIN_WIDTH / 2) - ((total_width / tile_count) / 2)
                    + width_offset,
                (STD_WIN_HEIGHT / 2) - ((total_width / tile_count) / 2)
                    + height_offset
            }, extra_data
        ),
        create_int_rect(0, 0, 150, total_width / tile_count)
    );
}

void init_sfx_music_buttons(sprites_t *sprites, extra_data_t *extra_data)
{
    init_sfx_icon(sprites, extra_data);
    init_music_icon(sprites, extra_data);
    init_music_status(sprites, extra_data);
    init_sfx_status(sprites, extra_data);
}
