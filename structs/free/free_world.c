/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** free_world
*/

#include "wolf3d.h"

void free_textures(sfTexture **textures, int nb_types)
{
    for (int i = 0; i < nb_types; i++) {
        if (textures[i]) {
            sfTexture_destroy(textures[i]);
        }
    }
}

void free_images(sfImage **images, int nb_types)
{
    for (int i = 0; i < nb_types; i++) {
        if (images[i]) {
            sfImage_destroy(images[i]);
        }
    }
}

void free_world(world_t *world)
{
    free_map(world->map, world->map_size_x, world->map_size_y);
    free_textures(world->wall_textures, NB_WALL_TYPES);
    free_textures(world->floor_textures, NB_FLOOR_TYPES);
    free_textures(world->ceiling_textures, NB_CEILING_TYPES);
    free_images(world->floor_images, NB_FLOOR_TYPES);
    free_images(world->ceiling_images, NB_CEILING_TYPES);
    free(world);
}
