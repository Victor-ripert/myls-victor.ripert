/*
** EPITECH PROJECT, 2024
** my_octal_nbr
** File description:
** desc
*/
#include "flags.h"
#include <stddef.h>

int special_case(int nb)
{
    if (nb == 0) {
        my_put_nbr(0);
        return 1;
    }
    return 0;
}

int my_octal_nbr(int nb)
{
    int array[20];
    int i = 0;
    int temp = special_case(nb);

    if (temp != 0)
        return temp;
    while (nb != 0) {
        array[i] = nb % 8;
        nb = nb / 8;
        i++;
    }
    temp = i;
    while (i != 0) {
        my_printf("%d", (array[i - 1]));
        i--;
    }
    return temp;
}
