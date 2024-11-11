/*
** EPITECH PROJECT, 2024
** my_put_long_hex
** File description:
** display long int into hex
*/
#include "flags.h"

long int unit_long_hex(long int nb)
{
    int i = 0;
    int j = 0;
    long int unit = 1;

    while (nb > 16){
        nb /= 16;
        unit *= 16;
    }
    return unit;
}

int my_put_long_hex(long int nb)
{
    long int res = 0;
    long int units;
    int dif_ascii_min = 87;
    int i = 0;

    units = unit_long_hex(nb);
    while (units > 0){
        res = nb / units;
        nb %= units;
        if (res > 9 && res < 16) {
            my_putchar(res + dif_ascii_min);
        } else {
            my_putchar(res + '0');
        }
        i++;
        units /= 16;
    }
    return i;
}
