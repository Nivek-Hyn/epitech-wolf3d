/*
** EPITECH PROJECT, 2025
** G-ING-210-MAR-2-1-wolf3d-hugo.sorgues [WSL: Ubuntu]
** File description:
** init_sfx
*/

#include "wolf3d.h"

static void init_hover_sfx(sfx_t *sfx, settings_t *settings)
{
    sfx->button_hover_buffer =
        sfSoundBuffer_createFromFile("assets/sfx/button_hover.wav");
    sfx->button_hover = sfSound_create();
    sfSound_setBuffer(sfx->button_hover, sfx->button_hover_buffer);
    sfSound_setVolume(sfx->button_hover, settings->sfx_volume);
}

static void init_click_sfx(sfx_t *sfx, settings_t *settings)
{
    sfx->button_click_buffer =
        sfSoundBuffer_createFromFile("assets/sfx/button_click.wav");
    sfx->button_click = sfSound_create();
    sfSound_setBuffer(sfx->button_click, sfx->button_click_buffer);
    sfSound_setVolume(sfx->button_click, settings->sfx_volume);
}

static void init_button_sfx(sfx_t *sfx, settings_t *settings)
{
    init_hover_sfx(sfx, settings);
    init_click_sfx(sfx, settings);
}

static void init_menu_music(sfx_t *sfx, settings_t *settings)
{
    sfx->menu_music = sfMusic_createFromFile("assets/sfx/AjouraMusic.mp3");
    sfMusic_setLoop(sfx->menu_music, sfTrue);
    sfMusic_setVolume(sfx->menu_music, settings->music_volume);
}

static void init_revolver_sfx(sfx_t *sfx, settings_t *settings)
{
    sfx->gunshot_buffer =
        sfSoundBuffer_createFromFile("assets/sfx/Gunshot.mp3");
    sfx->gunshot = sfSound_create();
    sfSound_setBuffer(sfx->gunshot, sfx->gunshot_buffer);
    sfSound_setVolume(sfx->gunshot, settings->sfx_volume);
    sfx->empty_gun_buffer =
        sfSoundBuffer_createFromFile("assets/sfx/EmptyGun.mp3");
    sfx->empty_gun = sfSound_create();
    sfSound_setBuffer(sfx->empty_gun, sfx->empty_gun_buffer);
    sfSound_setVolume(sfx->empty_gun, settings->sfx_volume);
}

void init_flashlight_sfx(sfx_t *sfx, settings_t *settings)
{
    sfx->flashlight_toggle_buffer =
        sfSoundBuffer_createFromFile("assets/sfx/FlashlightToggle.mp3");
    sfx->flashlight_toggle = sfSound_create();
    sfSound_setBuffer(sfx->flashlight_toggle, sfx->flashlight_toggle_buffer);
    sfSound_setVolume(sfx->flashlight_toggle, settings->sfx_volume);
    sfx->flashlight_battery_depleted_buffer =
        sfSoundBuffer_createFromFile("assets/sfx/Flashlight"
            "BatteryDepleted.mp3");
    sfx->flashlight_battery_depleted = sfSound_create();
    sfSound_setBuffer(sfx->flashlight_battery_depleted,
        sfx->flashlight_battery_depleted_buffer);
    sfSound_setVolume(sfx->flashlight_battery_depleted,
        settings->sfx_volume);
}

void init_footstep_sfx(sfx_t *sfx, settings_t *settings)
{
    sfx->footstep_buffer =
        sfSoundBuffer_createFromFile("assets/sfx/Footstep.mp3");
    sfx->footstep = sfSound_create();
    sfSound_setBuffer(sfx->footstep, sfx->footstep_buffer);
    sfSound_setVolume(sfx->footstep, settings->sfx_volume);
    sfx->footstep_two_buffer =
        sfSoundBuffer_createFromFile("assets/sfx/Footstep2.mp3");
    sfx->footstep_two = sfSound_create();
    sfSound_setBuffer(sfx->footstep_two, sfx->footstep_two_buffer);
    sfSound_setVolume(sfx->footstep_two, settings->sfx_volume);
    sfx->footstep_three_buffer =
        sfSoundBuffer_createFromFile("assets/sfx/Footstep3.mp3");
    sfx->footstep_three = sfSound_create();
    sfSound_setBuffer(sfx->footstep_three, sfx->footstep_three_buffer);
    sfSound_setVolume(sfx->footstep_three, settings->sfx_volume);
    sfx->footstep_four_buffer =
        sfSoundBuffer_createFromFile("assets/sfx/Footstep4.mp3");
    sfx->footstep_four = sfSound_create();
    sfSound_setBuffer(sfx->footstep_four, sfx->footstep_four_buffer);
    sfSound_setVolume(sfx->footstep_four, settings->sfx_volume);
}

sfx_t *init_sfx(settings_t *settings)
{
    sfx_t *sfx = malloc(sizeof(sfx_t));

    if (sfx == NULL)
        return NULL;
    init_menu_music(sfx, settings);
    init_button_sfx(sfx, settings);
    init_flashlight_sfx(sfx, settings);
    init_revolver_sfx(sfx, settings);
    init_footstep_sfx(sfx, settings);
    return sfx;
}
