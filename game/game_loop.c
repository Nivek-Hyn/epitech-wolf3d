/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** game_loop
*/

#include "wolf3d.h"

void game_render(game_t *game)
{
    draw_map(game);
    draw_items(game);
    draw_player(game);
    raycast(game);
    draw_world_items(game);
    draw_inventory(game, game->player->inventory);
    draw_selected_item_data(game);
    draw_interaction_message(game);
}

void time_manager(game_t *game)
{
    sfTime time = sfClock_restart(game->time->clock);

    game->time->delta_time = sfTime_asSeconds(time);
}

void game_loop(game_t *game)
{
    time_manager(game);
    check_events(game);
    update_player(game);
    update_mouse(game);
    check_interactions(game);
    update_gun_animation(game);
    game_render(game);
    pause_event(game);
}
