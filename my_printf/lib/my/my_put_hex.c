/*
** EPITECH PROJECT, 2024
** my_put_hex
** File description:
** display hexadecimal number
*/
#include "flags.h"

int unit_hex(int nb)
{
    int i = 0;
    int j = 0;
    int unit = 1;

    while (nb > 16){
        nb /= 16;
        unit *= 16;
    }
    return unit;
}

void print_hex(int res, int maj)
{
    int dif_ascii_maj = 55;
    int dif_ascii_min = 87;

    if (maj == 1) {
        my_putchar(res + dif_ascii_maj);
    } else {
        my_putchar(res + dif_ascii_min);
    }
}

int my_put_hex_it(int nb, int units, int maj)
{
    int i = 0;
    int res = 0;

    while (units > 0){
        res = nb / units;
        nb %= units;
        if (res > 9 && res < 16) {
            print_hex(res, maj);
        } else {
            my_putchar(res + '0');
        }
        units /= 16;
        i++;
    }
    return i;
}

int my_put_hex(int nb, int maj)
{
    int units;

    if (nb < 0){
        nb *= -1;
        my_putchar('-');
    }
    units = unit_hex(nb);
    return my_put_hex_it(nb, units, maj);
}
