/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** draw_player
*/

#include "wolf3d.h"

void draw_std_line(sfRenderWindow *render_win, sfVertex vert1, sfVertex vert2)
{
    sfVertexArray *vertex_array = sfVertexArray_create();

    sfVertexArray_append(vertex_array, vert1);
    sfVertexArray_append(vertex_array, vert2);
    sfVertexArray_setPrimitiveType(vertex_array, sfLines);
    sfRenderWindow_drawVertexArray(render_win, vertex_array, NULL);
    sfVertexArray_destroy(vertex_array);
}

void draw_player_orientation(game_t *game)
{
    sfVertexArray *vertex_array = sfVertexArray_create();

    sfVertexArray_append(vertex_array, (sfVertex){.position =
        (sfVector2f){game->player->x, game->player->y}, .color = sfGreen});
    sfVertexArray_append(vertex_array, (sfVertex){.position =
        (sfVector2f){(game->player->x + game->player->delta_x * SIGHT_LINE),
            (game->player->y + game->player->delta_y * SIGHT_LINE)},
                .color = sfGreen});
    sfVertexArray_setPrimitiveType(vertex_array, sfLines);
    sfRenderWindow_drawVertexArray(game->render_window, vertex_array, NULL);
    sfVertexArray_destroy(vertex_array);
}

void draw_player(game_t *game)
{
    sfCircleShape_setPosition(game->player->player_visual,
        (sfVector2f){game->player->x, game->player->y});
    sfRenderWindow_drawCircleShape(game->render_window,
        game->player->player_visual, NULL);
}
