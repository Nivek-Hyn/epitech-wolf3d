/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** load
*/

#include "wolf3d.h"

void load_world_items(game_t *game)
{
    item_manager_t *item_manager = game->item_manager;

    for (int i = 0; i < MAX_WORLD_ITEMS; i++) {
        if (item_manager->world_items[i].sprite)
            sfSprite_destroy(item_manager->world_items[i].sprite);
        if (item_manager->world_items[i].circle_visual)
            sfCircleShape_destroy(item_manager->world_items[i].circle_visual);
        if (item_manager->world_items[i].item.texture)
            sfTexture_destroy(item_manager->world_items[i].item.texture);
        if (item_manager->world_items[i].item.image)
            sfImage_destroy(item_manager->world_items[i].item.image);
        if (item_manager->world_items[i].item.data)
            free_item_data(item_manager->world_items[i].item.data,
                item_manager->world_items[i].item.type);
        reset_world_item(&item_manager->world_items[i]);
        item_manager->world_item_count--;
    }
    load_item_save_file(ITEM_SAVE_FILE, game->item_manager);
}

void load_map(game_t *game)
{
    free_map(game->world->map,
        game->world->map_size_x, game->world->map_size_y);
    if (load_map_file(SAVE_FILE, game->world) == -1) {
        game->world->map_size_x = STD_MATRIX_X;
        game->world->map_size_y = STD_MATRIX_Y;
        game->world->map = init_standard_map(
            game->world->map_size_x, game->world->map_size_y);
    }
    create_map(game->world);
}

void load(game_t *game)
{
    load_map(game);
    load_world_items(game);
}
