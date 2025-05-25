/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues [WSL: Ubuntu]
** File description:
** free_sprites
*/

#include "wolf3d.h"

static void free_buttons(sprites_t *sprites)
{
    free_sprite_sheet(sprites->btn_play);
    free_sprite_sheet(sprites->btn_settings);
    free_sprite_sheet(sprites->btn_quit);
    free_sprite_sheet(sprites->btn_return);
    free_sprite_sheet(sprites->btn_window_change);
    sfSprite_destroy(sprites->scp_logo);
    sfSprite_destroy(sprites->scp_icon);
}

void free_sprites(game_t *game)
{
    sfSprite_destroy(game->sprites->cursor);
    sfSprite_destroy(game->sprites->WindowMode_text);
    free_buttons(game->sprites);
    sfSprite_destroy(game->sprites->main_menu_background);
    free(game->sprites);
}
