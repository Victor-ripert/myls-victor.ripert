/*
** EPITECH PROJECT, 2024
** d_flag
** File description:
** from my_printf
*/
#include <stdarg.h>
#include "flags.h"

int d_flag(va_list arguments)
{
    int n = va_arg(arguments, int);
    int sum = my_put_nbr(n);

    return sum;
}
