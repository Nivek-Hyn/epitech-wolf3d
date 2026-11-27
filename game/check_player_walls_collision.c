/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** check wall collision
*/

#include "wolf3d.h"

int compare_lines_to_player(game_t *game, float player_pos_x,
    float player_pos_y, int y)
{
    float player_radius = sfCircleShape_getRadius(game->player->player_visual);

    for (int x = 0; x < game->world->map_size_x; x++) {
        if (game->world->map[y][x].wall_type == WALL &&
            check_circle_rectangle_collision(player_pos_x, player_pos_y,
                player_radius, game->world->map[y][x].wall_rectangle) == 1)
            return 1;
    }
    return (0);
}

int check_player_walls_collision(float player_pos_x, float player_pos_y,
    game_t *game)
{
    for (int y = 0; y < game->world->map_size_y; y++) {
        if (compare_lines_to_player(game, player_pos_x, player_pos_y, y) == 1)
            return (1);
    }
    return 0;
}
