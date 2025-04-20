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

void draw_wall_rectangle(game_t *game, raycast_values_t *var,
    float line_height, float line_offset)
{
    sfRectangleShape *rectangle = sfRectangleShape_create();
    float brightness = 255 / (var->total_dist / 100);
    float ray_spacing = (float)RAYCAST_WIN_WITDH / game->settings->ray_count;
    sfVector2f position = {RAY_OFFSET_X + var->drawn_rays * ray_spacing,
        RAY_OFFSET_Y + line_offset};
    sfVector2f size = {ray_spacing, line_height};
    sfColor wall_color = sfWhite;

    if (brightness > 255)
        brightness = 255;
    wall_color = sfColor_fromRGB(brightness, brightness, brightness);
    sfRectangleShape_setPosition(rectangle, position);
    sfRectangleShape_setSize(rectangle, size);
    sfRectangleShape_setFillColor(rectangle, wall_color);
    sfRenderWindow_drawRectangleShape(game->render_window, rectangle, NULL);
    sfRectangleShape_destroy(rectangle);
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
    if (line_height > RAYCAST_WIN_HEIGHT)
        line_height = RAYCAST_WIN_HEIGHT;
    line_offset = (RAYCAST_WIN_HEIGHT / 2) - (line_height / 2);
    draw_wall_rectangle(game, var, line_height, line_offset);
}
