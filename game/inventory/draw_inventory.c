/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** draw_inventory
*/

#include "wolf3d.h"

void draw_item_in_inventory_slot(game_t *game, item_t item,
    sfVector2f slot_pos, float scale)
{
    sfSprite *sprite = sfSprite_create();
    sfVector2f sprite_pos = {
        slot_pos.x + (INVENTORY_SLOT_SIZE * scale) / 2,
        slot_pos.y + (INVENTORY_SLOT_SIZE * scale) / 2
    };
    sfVector2u tex_size = sfTexture_getSize(item.texture);

    sfSprite_setTexture(sprite, item.texture, sfTrue);
    sfSprite_setOrigin(sprite, (sfVector2f){tex_size.x / 2, tex_size.y / 2});
    sfSprite_setPosition(sprite, sprite_pos);
    sfSprite_setScale(sprite, (sfVector2f){scale * 0.1, scale * 0.1});
    sfRenderWindow_drawSprite(game->render_window, sprite, NULL);
    sfSprite_destroy(sprite);
}

void draw_inventory_slot(game_t *game, sfVector2f pos, float scale)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfVector2f size =
        {INVENTORY_SLOT_SIZE * scale, INVENTORY_SLOT_SIZE * scale};
    sfColor fill_color = {INVENTORY_SLOT_BACKGROUND_COLOR};
    sfColor outline_color = INVENTORY_SLOT_BORDER_COLOR;
    float outline_thickness = INVENTORY_SLOT_OUTLINE_THICKNESS;

    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setPosition(rect, pos);
    sfRectangleShape_setFillColor(rect, fill_color);
    sfRectangleShape_setOutlineColor(rect, outline_color);
    sfRectangleShape_setOutlineThickness(rect, outline_thickness);
    sfRenderWindow_drawRectangleShape(game->render_window, rect, NULL);
    sfRectangleShape_destroy(rect);
}

sfVector2f get_inventory_slot_position(int i, float scale,
    float start_x, float y)
{
    float scaled_size = INVENTORY_SLOT_SIZE * scale;
    float offset = (scaled_size - INVENTORY_SLOT_SIZE) / 2;
    sfVector2f position;

    position.x = start_x + i *
        (INVENTORY_SLOT_SIZE + INVENTORY_SLOT_SPACING) - offset;
    position.y = y - offset;
    return position;
}

float get_transitioning_scale(int i, inventory_t *inventory, game_t *game)
{
    float target_scale = 1.0f;

    if (i == inventory->selected_slot)
        target_scale = INVENTORY_SLOT_SELECTED_SCALE;
    inventory->slot_scales[i] += (target_scale - inventory->slot_scales[i]) *
        game->time->delta_time * 10.0f;
    if (inventory->slot_scales[i] > INVENTORY_SLOT_SELECTED_SCALE) {
        inventory->slot_scales[i] = INVENTORY_SLOT_SELECTED_SCALE;
    } else if (inventory->slot_scales[i] < 1.0f) {
        inventory->slot_scales[i] = 1.0f;
    }
    return inventory->slot_scales[i];
}

void draw_inventory(game_t *game, inventory_t *inventory)
{
    float total_width = INVENTORY_SIZE * INVENTORY_SLOT_SIZE +
        (INVENTORY_SIZE - 1) * INVENTORY_SLOT_SPACING;
    float start_x = RAY_OFFSET_X + (RAYCAST_WIN_WITDH - total_width) / 2;
    float y_pos = RAY_OFFSET_Y + RAYCAST_WIN_HEIGHT -
        INVENTORY_SLOT_SIZE + INVENTORY_Y_OFFSET;
    float scale = 1.0f;
    sfVector2f pos;

    for (int i = 0; i < INVENTORY_SIZE; i++) {
        scale = get_transitioning_scale(i, inventory, game);
        pos = get_inventory_slot_position(i, scale, start_x, y_pos);
        draw_inventory_slot(game, pos, scale);
        if (inventory->slots[i].type != ITEM_NONE)
            draw_item_in_inventory_slot(game, inventory->slots[i], pos, scale);
    }
}
