/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** Mathieu Cauet & Victor Ripert
*/
#include "flags.h"
#include <stdarg.h>
#include <stddef.h>

const flags_t list[] = {
    {'d', d_flag},
    {'i', d_flag},
    {'c', c_flag},
    {'s', s_flag},
    {'x', x_flag},
    {'X', maj_x_flag},
    {'o', o_flag},
    {'%', prcent_flag},
    {'m', m_flag},
    {'g', g_flag},
    {'G', g_flag},
    {'u', u_flag},
    {'f', f_flag},
    {'F', f_flag},
    {'p', p_flag},
    {'e', e_flag},
    {'E', maj_e_flag},
    {'a', a_flag},
    {'A', a_flag},
    {'0', NULL}
};

int display_flags(char flag, va_list arguments, int sum)
{
    int i = 0;

    if (flag == 'n') {
        n_flag(arguments, sum);
        return sum;
    }
    while (list[i].flag != '0') {
        if (flag == list[i].flag) {
            sum += list[i].ptr_f(arguments);
        }
        i++;
    }
    return sum;
}

int my_printf(const char *format, ...)
{
    va_list arguments;
    int i = 0;
    int sum = 0;

    va_start(arguments, format);
    while (format[i] != '\0') {
        if (format[i] == '%') {
            sum = display_flags(format[i + 1], arguments, sum);
            i += 2;
        } else {
            my_putchar(format[i]);
            i++;
            sum++;
        }
    }
    va_end(arguments);
    return sum;
}
