/*
** EPITECH PROJECT, 2024
** c_flag
** File description:
** desc
*/
#include "flags.h"
#include <stdarg.h>

int c_flag(va_list arguments)
{
    my_putchar(va_arg(arguments, int));
    return 1;
}
