/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** init_window
*/

#include "wolf3d.h"

sfRenderWindow *init_window(void)
{
    char *win_name = "Wolf3D";
    sfVideoMode mode = {STD_WIN_WIDTH, STD_WIN_HEIGHT, 32};
    sfRenderWindow *window =
        sfRenderWindow_create(mode, win_name, sfDefaultStyle, NULL);

    return window;
}
