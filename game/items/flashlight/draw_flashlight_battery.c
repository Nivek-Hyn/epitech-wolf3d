/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** draw_flashlight_battery
*/

#include "wolf3d.h"

void draw_flashlight_battery_background(sfRenderWindow *win, float x, float y)
{
    sfRectangleShape *bg = create_rectangle(
        (sfVector2f){x, y},
        (sfVector2f){MAX_BATTERY_WIDTH, 50},
        sfWhite,
        sfColor_fromRGB(50, 50, 50));

    sfRenderWindow_drawRectangleShape(win, bg, NULL);
    sfRectangleShape_destroy(bg);
}

void draw_flashlight_battery_bar(sfRenderWindow *win,
    float x, float y, float percent)
{
    float width = (percent / 100.0f) * MAX_BATTERY_WIDTH;
    sfVector2f size = {width, 50};
    sfRectangleShape *bar =
        create_rectangle((sfVector2f){x, y}, size, sfWhite, sfGreen);

    if (percent > 50) {
        sfRectangleShape_setFillColor(bar, sfGreen);
    } else if (percent > 25) {
        sfRectangleShape_setFillColor(bar, sfYellow);
    } else {
        sfRectangleShape_setFillColor(bar, sfRed);
    }
    sfRenderWindow_drawRectangleShape(win, bar, NULL);
    sfRectangleShape_destroy(bar);
}

void draw_flashlight_battery_text(sfRenderWindow *win, sfFont *font,
    sfVector2f pos, float percent)
{
    char text_str[5];
    sfText *text = sfText_create();
    sfFloatRect bounds;
    sfVector2f text_pos;

    snprintf(text_str, sizeof(text_str), "%d%%", (int)percent);
    sfText_setFont(text, font);
    sfText_setString(text, text_str);
    sfText_setCharacterSize(text, 25);
    sfText_setFillColor(text, sfWhite);
    bounds = sfText_getLocalBounds(text);
    text_pos = (sfVector2f){
        pos.x + (MAX_BATTERY_WIDTH / 2) - (bounds.width / 2),
        pos.y + (50 / 2) - (bounds.height / 2) - 5
    };
    sfText_setPosition(text, text_pos);
    sfRenderWindow_drawText(win, text, NULL);
    sfText_destroy(text);
}

void draw_flashlight_battery(game_t *game, flashlight_t *flashlight)
{
    float current = flashlight->battery;
    float percent = (current / MAX_FLASHLIGHT_BATTERY) * 100.0f;
    sfVector2f pos = {
        .x = RAYCAST_WIN_X_CENTER / 2 - MAX_FLASHLIGHT_BATTERY / 2,
        .y = RAYCAST_WIN_Y_CENTER / 2 - 25
    };

    draw_flashlight_battery_background(game->render_window, pos.x, pos.y);
    draw_flashlight_battery_bar(game->render_window, pos.x, pos.y, percent);
    draw_flashlight_battery_text(game->render_window,
        game->fonts->normal, pos, percent);
}
