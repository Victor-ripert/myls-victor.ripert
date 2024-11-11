/*
** EPITECH PROJECT, 2024
** x_flag
** File description:
** desc
*/
#include "flags.h"
#include <stdarg.h>

int x_flag(va_list arguments)
{
    int sum = 0;
    int x = va_arg(arguments, int);

    sum = my_put_hex(x, 0);
    return sum;
}
