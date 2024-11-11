/*
** EPITECH PROJECT, 2024
** e_flag
** File description:
** e flag from my_printf
*/
#include <stdarg.h>
#include "flags.h"

int e_flag(va_list arguments)
{
    double arg = va_arg(arguments, double);

    my_put_scientific_notation(arg, 'e');
    return 12;
}
