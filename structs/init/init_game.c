/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** init_game
*/

#include "wolf3d.h"

static void init_game_more(game_t *game)
{
    game->settings_cooldown = sfClock_create();
    game->sfx_cooldown = sfClock_create();
    game->sounds = init_sfx(game->settings);
    game->is_paused = false;
    game->effects = init_effects(game);
}

game_t *init_game_struct(void)
{
    game_t *game = malloc(sizeof(game_t));

    if (!game)
        return NULL;
    game->render_window = init_window();
    game->fonts = init_fonts();
    game->player = init_player(game);
    game->settings = init_settings();
    game->world = init_world();
    game->keys = init_keys();
    game->mouse = init_mouse();
    game->time = init_time();
    game->texts = init_texts(game->fonts);
    game->item_manager = init_item_manager();
    game->extra_data = init_extra_data();
    game->current_scene = init_scene_enum();
    game->precedent_scene = init_scene_enum();
    game->sprites = init_sprites(game->extra_data);
    init_game_more(game);
    return game;
}
