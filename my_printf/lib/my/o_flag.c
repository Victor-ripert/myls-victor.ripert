/*
** EPITECH PROJECT, 2024
** o_flag
** File description:
** desc
*/
#include "flags.h"
#include <stdarg.h>

int o_flag(va_list arguments)
{
    int sum = my_octal_nbr(va_arg(arguments, int));

    return sum;
}
