/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** draw_3d_walls
*/

#include "wolf3d.h"

void draw_wall_line(game_t *game, raycast_values_t *var,
    float line_height, float line_offset)
{
    sfVertexArray *vertex_array = sfVertexArray_create();

    sfVertexArray_append(vertex_array,
        (sfVertex){.position = (sfVector2f){RAY_OFFSET_X + var->drawn_rays *
            RAYCAST_JUMP, line_offset}, .color = sfWhite});
    sfVertexArray_append(vertex_array,
        (sfVertex){.position = (sfVector2f){RAY_OFFSET_X + var->drawn_rays *
            RAYCAST_JUMP, line_height + line_offset}, .color = sfWhite});
    sfVertexArray_setPrimitiveType(vertex_array, sfLines);
    sfRenderWindow_drawVertexArray(game->render_window, vertex_array, NULL);
    sfVertexArray_destroy(vertex_array);
}

void draw_3d_walls(game_t *game, raycast_values_t *var)
{
    float co_angle = 0.0;
    float corrected_dist = 0.0;
    float line_height = 0.0;
    float line_offset = 0.0;

    co_angle = game->player->angle - var->ray_angle;
    co_angle = limit_trigo_angle(co_angle);
    corrected_dist = var->total_dist * cos(co_angle);
    line_height = (TILE_SIZE * RAYCAST_WIN_HEIGHT) / corrected_dist;
    line_offset = (RAYCAST_WIN_HEIGHT / 2) - (line_height / 2);
    draw_wall_rectangle(game, var, line_height, line_offset);
}
