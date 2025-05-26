/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** update_player_data
*/

#include "wolf3d.h"

void update_player_stamina(game_t *game)
{
    if (game->keys->shift == 1) {
        if (game->player->stamina->current > 0) {
            game->player->stamina->current -=
                game->time->delta_time * STAMINA_RUN_COST;
        } else {
            game->keys->shift = 0;
            game->player->move_speed = MOVE_SPEED;
        }
    } else if (game->player->stamina->current < game->player->stamina->max) {
        game->player->stamina->current +=
            game->time->delta_time * game->player->stamina->regen_rate;
    }
}

void update_player_data(game_t *game)
{
    update_player_stamina(game);
}
