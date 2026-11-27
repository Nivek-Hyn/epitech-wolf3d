/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** sprite_create
*/

#include "wolf3d.h"

sfSprite *sprite_create(char *filepath, float scale, sfVector2f position,
    extra_data_t *extra_data)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);
    sfVector2f scale_vector = {scale, scale};

    extra_data->nb_textures++;
    extra_data->textures = realloc(extra_data->textures,
        sizeof(sfTexture *) * (extra_data->nb_textures + 1));
    extra_data->textures[extra_data->nb_textures - 1] = texture;
    extra_data->textures[extra_data->nb_textures] = NULL;
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, scale_vector);
    sfSprite_setPosition(sprite, position);
    return (sprite);
}
