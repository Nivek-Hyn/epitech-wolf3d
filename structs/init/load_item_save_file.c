/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** load_item_save_file
*/

#include "wolf3d.h"

static sfVector2f get_item_position(int pos_type, float x, float y)
{
    sfVector2f position;

    if (pos_type == 1) {
        position.x = x * TILE_SIZE + (TILE_SIZE / 2);
        position.y = y * TILE_SIZE + (TILE_SIZE / 2);
    } else {
        position.x = x;
        position.y = y;
    }
    return position;
}

void load_item_save_file(const char *filename, item_manager_t *manager)
{
    FILE * file = fopen(filename, "r");
    int type = 0;
    int quantity = 0;
    int pos_type = 0;
    float x = 0.0f;
    float y = 0.0f;

    if (!file)
        return;
    while (fscanf(file, "%d %d %d %f %f",
            &type, &quantity, &pos_type, &x, &y) == 5) {
        if (type < ITEM_NONE || type >= ITEM_TYPE_COUNT)
            continue;
        if (manager->world_item_count >= MAX_WORLD_ITEMS)
            break;
        spawn_item(manager, create_item(type),
            get_item_position(pos_type, x, y));
    }
    fclose(file);
}
