/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** save
*/

#include "wolf3d.h"

void save_world_items(FILE *item_file, game_t *game)
{
    world_item_t *world_item = NULL;
    item_t *item = NULL;
    sfVector2f pos;

    for (int i = 0; i < game->item_manager->world_item_count; i++) {
        world_item = &game->item_manager->world_items[i];
        item = &world_item->item;
        pos = world_item->position;
        fprintf(item_file, "%d %d %d %.1f %.1f\n",
            item->type, item->quantity, 0, pos.x, pos.y);
    }
}

void save_ceiling_map(FILE *save_file, game_t *game)
{
    for (int y = 0; y < game->world->map_size_y; y++) {
        for (int x = 0; x < game->world->map_size_x; x++) {
            fprintf(save_file, "%d ", game->world->map[y][x].ceiling_type);
        }
        fprintf(save_file, "\n");
    }
}

void save_floor_map(FILE *save_file, game_t *game)
{
    for (int y = 0; y < game->world->map_size_y; y++) {
        for (int x = 0; x < game->world->map_size_x; x++) {
            fprintf(save_file, "%d ", game->world->map[y][x].floor_type);
        }
        fprintf(save_file, "\n");
    }
    fprintf(save_file, "\n");
}

void save_wall_map(FILE *save_file, game_t *game)
{
    for (int y = 0; y < game->world->map_size_y; y++) {
        for (int x = 0; x < game->world->map_size_x; x++) {
            fprintf(save_file, "%d ", game->world->map[y][x].wall_type);
        }
        fprintf(save_file, "\n");
    }
    fprintf(save_file, "\n");
}

void save(game_t *game)
{
    FILE *save_file = fopen(SAVE_FILE, "w");
    FILE *item_file = fopen(ITEM_SAVE_FILE, "w");

    if (!save_file || !item_file)
        return;
    fprintf(save_file, "%d %d\n\n",
        game->world->map_size_x, game->world->map_size_y);
    save_wall_map(save_file, game);
    save_floor_map(save_file, game);
    save_ceiling_map(save_file, game);
    save_world_items(item_file, game);
    fclose(save_file);
    fclose(item_file);
}
