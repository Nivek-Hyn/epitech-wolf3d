/*
** EPITECH PROJECT, 2024
** nbr_to_str
** File description:
** number to a string
*/

#include "wolf3d.h"

int nbr_to_str_check(int *nb, int *is_negative)
{
    if (*nb == 0)
        return 1;
    if (*nb < 0) {
        *is_negative = 1;
        *nb = -(*nb);
    }
    return 0;
}

void nbr_to_str_zero(int nb, char *str, int i)
{
    if (nb == 0) {
        str[i] = '0';
        str[i + 1] = '\0';
        return;
    }
}

char *nbr_to_str(int nb)
{
    int i = 0;
    int is_negative = 0;
    int length = ((nb < 0) ? nbr_of_digits(nb) +1 : nbr_of_digits(nb));
    char *str = malloc(sizeof(char) * (length + 1));

    nbr_to_str_zero(nb, str, i);
    if (nbr_to_str_check(&nb, &is_negative) == 1)
        return str;
    while (nb != 0) {
        str[i] = (nb % 10) + '0';
        nb /= 10;
        i++;
    }
    if (is_negative) {
        str[i] = '-';
        i++;
    }
    str[i] = '\0';
    my_revstr(str);
    return str;
}
