/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** draw_gun_data
*/

#include "wolf3d.h"

void draw_gun(game_t *game, gun_t *gun)
{
    sfIntRect rect = gun->gun_ss->int_rect[gun->gun_anim_frame];
    sfVector2f pos = {
        RAYCAST_WIN_X_CENTER - rect.width / 2.0f,
        RAYCAST_WIN_Y_CENTER + 250 - rect.height / 2.0f
    };

    sfSprite_setPosition(gun->gun_ss->sprite, pos);
    sfRenderWindow_drawSprite(game->render_window, gun->gun_ss->sprite, NULL);
}

void draw_gun_data(game_t *game, item_t selected_slot)
{
    gun_t *gun = (gun_t *)selected_slot.data;
    char *text = nbr_to_str(gun->ammo);
    sfVector2f ammo_pos = {
        .x = RAYCAST_WIN_X_CENTER / 2,
        .y = RAYCAST_WIN_Y_CENTER / 2
    };

    if (gun == NULL)
        return;
    text = strcat(text, "/6");
    draw_text(game, text, 30, ammo_pos);
    sfSprite_setPosition(game->sprites->ammo_icon,
        (sfVector2f){ammo_pos.x - 75, ammo_pos.y - 35});
    sfRenderWindow_drawSprite(game->render_window,
        game->sprites->ammo_icon, NULL);
    draw_gun(game, gun);
    free(text);
}
