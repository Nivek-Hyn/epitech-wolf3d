/*
** EPITECH PROJECT, 2025
** nbr_of_digits.c
** File description:
** return the number of digits of an integer
*/

#include "wolf3d.h"

int nbr_of_digits(int nb)
{
    int count = 0;

    if (nb == 0)
        return 1;
    if (nb < 0)
        nb = -nb;
    while (nb > 0) {
        nb /= 10;
        count++;
    }
    return count;
}
