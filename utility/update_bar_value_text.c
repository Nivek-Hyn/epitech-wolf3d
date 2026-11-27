/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues
** File description:
** update_bar_value_text
*/

#include "wolf3d.h"

void update_bar_value_text(float current, float max,
    sfText *value_text, bar_display_mode_t mode)
{
    char *buffer = NULL;
    int needed = 0;
    float percent = 0.0f;

    if (mode == BAR_DISPLAY_PERCENT) {
        percent = 0.0f;
        if (max > 0)
            percent = (int)((current / max) * 100);
        needed = snprintf(NULL, 0, "%.0f%%", percent) + 1;
        buffer = malloc(needed);
        snprintf(buffer, needed, "%.0f%%", percent);
    } else {
        needed = snprintf(NULL, 0, "%.0f", current) + 1;
        buffer = malloc(needed);
        snprintf(buffer, needed, "%.0f", current);
    }
    sfText_setString(value_text, buffer);
    free(buffer);
}
