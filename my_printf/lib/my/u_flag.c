/*
** EPITECH PROJECT, 2024
** u_flag
** File description:
** u flag from my_printf
*/
#include <stdarg.h>
#include "flags.h"

int my_unit(unsigned int nb)
{
    int i = 0;
    int j = 0;
    int unit = 1;

    while (nb > 10){
        nb /= 10;
        unit *= 10;
    }
    return unit;
}

int my_unsigned(unsigned int nb)
{
    int res = 0;
    int units;
    int i = 0;

    if (nb < 0){
        nb *= -1;
        my_putchar('-');
    }
    units = my_unit(nb);
    while (units > 0){
        res = nb / units;
        nb %= units;
        my_putchar(res + 48);
        units /= 10;
        i++;
    }
    return i;
}

int u_flag(va_list arguments)
{
    my_unsigned(va_arg(arguments, unsigned int));
}
