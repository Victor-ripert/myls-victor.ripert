/*
** EPITECH PROJECT, 2024
** P_flag
** File description:
** P flag from my_printf
*/
#include <stdarg.h>
#include "flags.h"
#include <stdio.h>

int p_flag(va_list arguments)
{
    int *adresse = va_arg(arguments, void *);
    long int long_adresse = (long int)adresse;
    int sum = 0;

    sum += my_putstr("0x");
    sum += my_put_long_hex(long_adresse);
    return sum;
}
