/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues [WSL: Ubuntu]
** File description:
** init_pause_btn
*/

#include "wolf3d.h"

void init_pause_save_button(sprites_t *sprites, extra_data_t *extra_data)
{
    unsigned height_offset = 20;
    unsigned tile_count = 2;
    unsigned total_width = 900;
    unsigned tile_width = total_width / tile_count;

    sprites->pause_btn_save = init_sprite_sheet(
        tile_count,
        sprite_create(
            "assets/textures/buttons/BTN_Save.png",
            1.0,
            (sfVector2f){
                (STD_WIN_WIDTH / 2) - ((total_width / tile_count) / 2),
                (STD_WIN_HEIGHT / 2) - ((total_width / tile_count) / 2)
                    - height_offset
            },
            extra_data
        ),
        create_int_rect(0, 0, 150, total_width / tile_count)
    );
}

void init_pause_load_button(sprites_t *sprites, extra_data_t *extra_data)
{
    unsigned height_offset = 110 + 15;
    unsigned tile_count = 2;
    unsigned total_width = 900;
    unsigned tile_width = total_width / tile_count;

    sprites->pause_btn_load = init_sprite_sheet(
        tile_count,
        sprite_create(
            "assets/textures/buttons/BTN_Load.png",
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
