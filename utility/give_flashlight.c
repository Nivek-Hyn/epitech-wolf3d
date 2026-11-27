/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** give_flashlight
*/

#include "wolf3d.h"

void give_flashlight(inventory_t *inventory, int slot)
{
    flashlight_t *flashlight = NULL;

    if (slot < 0 || slot >= INVENTORY_SIZE)
        return;
    flashlight = malloc(sizeof(flashlight_t));
    if (!flashlight)
        return;
    flashlight->is_on = false;
    flashlight->battery = 100.0f;
    inventory->slots[slot].type = ITEM_FLASHLIGHT;
    inventory->slots[slot].quantity++;
    inventory->slots[slot].texture = sfTexture_createFromFile(
        "assets/textures/items/flashlight.png", NULL);
    inventory->slots[slot].image = sfImage_createFromFile(
        "assets/textures/items/flashlight.png");
    inventory->slots[slot].data = flashlight;
}
