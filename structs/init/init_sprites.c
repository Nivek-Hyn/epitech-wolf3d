/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues [WSL: Ubuntu]
** File description:
** init_sprites
*/

#include "wolf3d.h"

static void init_main_menu_background(sprites_t *sprites)
{
    sprites->main_menu_background = sprite_create(
        "assets/textures/scp_background_blured.png",
        1.4,
        (sfVector2f){0, 0}
    );
}

static void init_play_button(sprites_t *sprites)
{
    unsigned height_offset = 100;
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
        create_int_rect(0, 0, 150, 900 / 2)
    );
}

static void init_settings_button(sprites_t *sprites)
{
    unsigned height_offset = 250;
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
        create_int_rect(0, 0, 150, 900 / 2)
    );
}

static void init_quit_button(sprites_t *sprites)
{
    unsigned height_offset = 400;
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
        create_int_rect(0, 0, 150, 900 / 2)
    );
}

sprites_t *init_sprites(void)
{
    sprites_t *sprites = malloc(sizeof(sprites_t));

    if (sprites == NULL)
        return NULL;
    init_play_button(sprites);
    init_settings_button(sprites);
    init_quit_button(sprites);
    init_main_menu_background(sprites);
    return sprites;
}
