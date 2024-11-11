/*
** EPITECH PROJECT, 2024
** n_flag
** File description:
** desc
*/
#include "flags.h"
#include <stdarg.h>
#include <stdio.h>

int n_flag(va_list arguments, int num)
{
    int *ptr = va_arg(arguments, int *);

    ptr[0] = num;
    return 0;
}
