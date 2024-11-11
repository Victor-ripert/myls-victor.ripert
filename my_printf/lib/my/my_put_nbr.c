/*
** EPITECH PROJECT, 2024
** my_put_nbr
** File description:
** desc
*/
#include "flags.h"

int unit(int nb)
{
    int unit = 1;

    while (nb >= 10){
        nb /= 10;
        unit *= 10;
    }
    return unit;
}

int my_put_nbr(int nb)
{
    int res = 0;
    int units;
    int i = 0;

    if (nb < 0){
        nb *= -1;
        my_putchar('-');
    }
    units = unit(nb);
    while (units > 0){
        res = nb / units;
        nb %= units;
        my_putchar(res + '0');
        units /= 10;
        i++;
    }
    return i;
}
