/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** create_flashlight
*/

#include "wolf3d.h"

void *create_flashlight(void)
{
    flashlight_t *flashlight = malloc(sizeof(flashlight_t));

    if (!flashlight)
        return NULL;
    flashlight->is_on = false;
    flashlight->battery = 100.0f;
    flashlight->sheet = sfTexture_createFromFile(
        "assets/textures/items/flashlight_sheet.png", NULL);
    flashlight->flashlight_ss = create_sprite_sheet(flashlight->sheet, 2);
    sfSprite_setTextureRect(
        flashlight->flashlight_ss->sprite,
        flashlight->flashlight_ss->int_rect[0]
    );
    return (void *)flashlight;
}
