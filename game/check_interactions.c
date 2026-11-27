/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** check_interactions
*/

#include "wolf3d.h"

bool check_if_player_can_interact(game_t *game)
{
    for (int i = 0; i < MAX_WORLD_ITEMS; i++) {
        if (game->item_manager->world_items[i].can_interact == true)
            return true;
    }
    return false;
}

void world_item_interact(game_t *game, world_item_t *world_item, int index)
{
    if (pickup_item(game->player, game->item_manager, index)) {
        game->player->interact = false;
        world_item->can_interact = false;
    } else {
        draw_inventory_full_message(game, 1);
        game->player->interact = false;
        world_item->can_interact = false;
    }
}

bool check_item_requirements_for_interaction(game_t *game,
    world_item_t *world_item)
{
    float distance = sqrtf(
        powf(game->player->x - world_item->position.x, 2) +
        powf(game->player->y - world_item->position.y, 2));
    sfVector2f aiming_point = {
        .x = RAY_OFFSET_X + RAYCAST_WIN_WITDH / 2,
        .y = RAY_OFFSET_Y + RAYCAST_WIN_HEIGHT / 2
    };
    sfFloatRect bounds = sfSprite_getGlobalBounds(world_item->sprite);

    if (distance < INTERACTION_RANGE && world_item->is_visible &&
        sfFloatRect_contains(&bounds, aiming_point.x, aiming_point.y)) {
        game->player->can_interact = true;
        world_item->can_interact = true;
        return true;
    } else {
        world_item->can_interact = false;
        return false;
    }
}

void check_world_items_interactions(game_t *game)
{
    item_manager_t *manager = game->item_manager;
    world_item_t *world_item = NULL;

    for (int i = 0; i < MAX_WORLD_ITEMS; i++) {
        if (manager->world_items[i].item.type == ITEM_NONE)
            continue;
        world_item = &manager->world_items[i];
        if (check_item_requirements_for_interaction(game, world_item) &&
                game->player->interact) {
            world_item_interact(game, world_item, i);
            break;
        }
    }
}

void check_interactions(game_t *game)
{
    check_world_items_interactions(game);
    if (check_if_player_can_interact(game) == true) {
        game->player->can_interact = true;
    } else {
        game->player->can_interact = false;
    }
    game->player->interact = false;
    draw_inventory_full_message(game, 0);
}
