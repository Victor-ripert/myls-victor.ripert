/*
** EPITECH PROJECT, 2024
** f_flag
** File description:
** f flag from my_printf
*/
#include <stdarg.h>
#include "flags.h"

int f_flag(va_list arguments)
{
    int len = my_put_float(va_arg(arguments, double));

    return len;
}
