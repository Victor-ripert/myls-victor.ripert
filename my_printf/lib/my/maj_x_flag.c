/*
** EPITECH PROJECT, 2024
** maj_x_flag
** File description:
** uppercase maj_x_flag
*/

#include "flags.h"
#include <stdarg.h>

int maj_x_flag(va_list arguments)
{
    int sum = 0;
    int x = va_arg(arguments, int);

    sum = my_put_hex(x, 1);
    return sum;
}
