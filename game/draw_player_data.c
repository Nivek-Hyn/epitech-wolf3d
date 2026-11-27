/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** draw_player_bars
*/

#include "wolf3d.h"

void update_bar(bar_components_t *bar,
    float current, float max, sfColor color)
{
    float ratio = current / max;
    float new_width = bar->size.x * ratio;

    sfRectangleShape_setSize(bar->bar, (sfVector2f){new_width, bar->size.y});
    sfRectangleShape_setFillColor(bar->bar, color);
}

void draw_health_bar(sfRenderWindow *window, player_t *player)
{
    sfColor health_color;

    if (player->health->current > player->health->max * 0.5f) {
        health_color = sfGreen;
    } else if (player->health->current > player->health->max * 0.25f) {
        health_color = sfYellow;
    } else {
        health_color = sfRed;
    }
    update_bar(player->health->health_bar, player->health->current,
        player->health->max, health_color);
    update_bar_value_text(player->health->current, player->health->max,
        player->health->health_bar->value_text, BAR_DISPLAY_PERCENT);
    draw_bar(window, player->health->health_bar, (sfVector2f){
        RAYCAST_WIN_X_CENTER * 1.5f - MAX_PLAYER_HEALTH_BAR / 2 + 100.0f,
        RAYCAST_WIN_Y_CENTER / 2 - 100.0f});
}

void draw_stamina_bar(sfRenderWindow *window, player_t *player)
{
    update_bar(player->stamina->stamina_bar, player->stamina->current,
        player->stamina->max, sfYellow);
    update_bar_value_text(player->stamina->current, player->stamina->max,
        player->stamina->stamina_bar->value_text, BAR_DISPLAY_PERCENT);
    draw_bar(window, player->stamina->stamina_bar, (sfVector2f){
        RAYCAST_WIN_X_CENTER * 1.5f - MAX_PLAYER_STAMINA_BAR / 2 + 100.0f,
        RAYCAST_WIN_Y_CENTER / 2 - 25.0f});
}

void draw_player_data(game_t *game, player_t *player)
{
    draw_health_bar(game->render_window, player);
    draw_stamina_bar(game->render_window, player);
}
