/*
** EPITECH PROJECT, 2024
** c_flag
** File description:
** from my_printf
*/
#include "flags.h"
#include <stdarg.h>

int s_flag(va_list arguments)
{
    return my_putstr(va_arg(arguments, char *));
}
