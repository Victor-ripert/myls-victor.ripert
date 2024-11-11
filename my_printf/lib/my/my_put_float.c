/*
** EPITECH PROJECT, 2024
** my_put_float
** File description:
** desc
*/
#include "flags.h"
#include <stdarg.h>
int special_case_0(void)
{
    int i = 0;

    while (i <= 5) {
        my_put_nbr(0);
        i++;
    }
    return i;
}

int special_case_float(double nb)
{
    int comma = 10;
    int temp = nb * comma;
    int len = 0;

    while ((temp % 10) == 0) {
        len += my_put_nbr(0);
        comma *= 10;
        temp = nb * comma;
    }
    return len;
}

int get_decimal(double nb)
{
    int non_float;

    non_float = nb * 1000000;
    return (non_float % 1000000);
}

int my_put_float(float nb)
{
    double to_arround_nb = 0.0000004;
    int len = 0;
    int decimal;
    int nb_no_decimal = nb;

    nb += to_arround_nb;
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    len = my_put_nbr(nb);
    my_putchar('.');
    decimal = get_decimal(nb);
    if (decimal == 0)
        return (len + special_case_0());
    len += special_case_float(nb);
    len += my_put_nbr(decimal);
    return len;
}
