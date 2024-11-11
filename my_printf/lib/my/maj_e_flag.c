/*
** EPITECH PROJECT, 2024
** maj_e_flag
** File description:
** %E flag from my_printf
*/
#include <stdarg.h>
#include "flags.h"

int maj_e_flag(va_list arguments)
{
    double arg = va_arg(arguments, double);

    my_put_scientific_notation(arg, 'E');
    return 12;
}
