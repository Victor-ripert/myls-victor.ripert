/*
** EPITECH PROJECT, 2024
** flags.h
** File description:
** flags structure & functions for my_printf
*/
#include <stdarg.h>

#ifndef FILE_H
    #define FILE_H
int my_printf(const char *format, ...);
typedef struct {
    char flag;
    int (*ptr_f)(va_list);
} flags_t;
void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_put_hex(int nb, int maj);
int my_put_long_hex(long int nb);
int my_octal_nbr(int nb);
int my_put_float(float nb);
int my_intlen(int nb);
int my_put_scientific_notation(double arg, char e);
int d_flag(va_list arguments);
int s_flag(va_list arguments);
int c_flag(va_list arguments);
int o_flag(va_list arguments);
int u_flag(va_list arguments);
int x_flag(va_list arguments);
int maj_x_flag(va_list arguments);
int e_flag(va_list arguments);
int maj_e_flag(va_list arguments);
int f_flag(va_list arguments);
int g_flag(va_list arguments);
int a_flag(va_list arguments);
int p_flag(va_list arguments);
int n_flag(va_list arguments, int sum);
int m_flag(va_list arguments);
int prcent_flag(va_list arguments);
#endif /* FILE_H */
