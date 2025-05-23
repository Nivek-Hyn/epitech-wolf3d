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
        1.0,
        (sfVector2f){0, 0}
    );
}

static void init_play_button(sprites_t *sprites)
{
    sprites->btn_play = init_sprite_sheet(
        2,
        sprite_create(
            "assets/textures/buttons/BTN_Play.png",
            1.0,
            (sfVector2f){0, 0}
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
    init_main_menu_background(sprites);
    return sprites;
}
