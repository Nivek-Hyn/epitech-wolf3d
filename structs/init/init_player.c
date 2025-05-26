/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** init_player
*/

#include "wolf3d.h"

health_t *init_health(sfFont *font)
{
    health_t *health = malloc(sizeof(health_t));

    health->health_bar = malloc(sizeof(bar_components_t));
    health->max = 100.0f;
    health->current = 100.0f;
    health->regen_rate = HEALTH_REGEN_RATE;
    *health->health_bar = (bar_components_t){
        .size = (sfVector2f){MAX_PLAYER_HEALTH_BAR, 50},
        .background_color = sfColor_fromRGBA(50, 50, 50, 255),
        .outline_color = sfWhite, .outline_thickness = 2.0f,
        .value_text_size = 25, .value_text_color = sfBlack,
        .label_text_size = 25, .label_text_color = sfWhite,
        .font = font
    };
    init_bar_components(health->health_bar);
    update_bar_value_text(health->current, health->max,
        health->health_bar->value_text, BAR_DISPLAY_PERCENT);
    sfText_setString(health->health_bar->label_text, "Health");
    return health;
}

stamina_t *init_stamina(sfFont *font)
{
    stamina_t *stamina = malloc(sizeof(stamina_t));

    stamina->stamina_bar = malloc(sizeof(bar_components_t));
    stamina->max = 100.0f;
    stamina->current = 100.0f;
    stamina->regen_rate = STAMINA_REGEN_RATE;
    *stamina->stamina_bar = (bar_components_t){
        .size = (sfVector2f){MAX_PLAYER_STAMINA_BAR, 50},
        .background_color = sfColor_fromRGBA(50, 50, 50, 255),
        .outline_color = sfWhite, .outline_thickness = 2.0f,
        .value_text_size = 25, .value_text_color = sfBlack,
        .label_text_size = 25, .label_text_color = sfWhite,
        .font = font
    };
    init_bar_components(stamina->stamina_bar);
    update_bar_value_text(stamina->current, stamina->max,
        stamina->stamina_bar->value_text, BAR_DISPLAY_PERCENT);
    sfText_setString(stamina->stamina_bar->label_text, "Stamina");
    return stamina;
}

inventory_t *init_inventory(void)
{
    inventory_t *inventory = malloc(sizeof(inventory_t));

    if (!inventory)
        return NULL;
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        reset_inventory_slot(inventory, i);
        inventory->slot_scales[i] = 1.0f;
    }
    inventory->selected_slot = 0;
    return inventory;
}

player_t *init_player(game_t *game)
{
    player_t *player = malloc(sizeof(player_t));

    if (!player)
        return NULL;
    player->x = TILE_SIZE + (TILE_SIZE / 2);
    player->y = TILE_SIZE + (TILE_SIZE / 2);
    player->angle = 0;
    player->delta_x = (cos(player->angle) * MOVE_SPEED);
    player->delta_y = (sin(player->angle) * MOVE_SPEED);
    player->move_speed = MOVE_SPEED;
    player->player_visual = create_circle((sfVector2f){player->x, player->y},
        PLAYER_RADIUS, sfWhite, sfGreen);
    player->inventory = init_inventory();
    player->can_interact = false;
    player->interact = false;
    player->health = init_health(game->fonts->normal);
    player->stamina = init_stamina(game->fonts->normal);
    player->sanity = 100.0f;
    return player;
}
