/*
** EPITECH PROJECT, 2024
** my_put_nbr
** File description:
** desc
*/
#include "my.h"
#include <stdlib.h>

int unit(int nb)
{
    int unit = 1;

    while (nb >= 10){
        nb /= 10;
        unit *= 10;
    }
    return unit;
}

int my_intlen(int nb)
{
    int count = 0;

    if (nb < 0) {
        nb = nb * -1;
        count++;
    }
    while (nb > 0) {
        nb = nb / 10;
        count++;
    }
    return count;
}

char *nbr_to_str(int nb)
{
    int res = 0;
    int units;
    int i = 0;
    int int_len = my_intlen(nb);
    char *result = malloc(sizeof(char) * int_len);
    int indice_result = 0;

    if (nb < 0){
        nb *= -1;
	result[indice_result] = '-';
	indice_result++;
    }
    units = unit(nb);
    while (units > 0){
        res = nb / units;
        nb %= units;
	result[indice_result] = res;
	indice_result++;
        units /= 10;
        i++;
    }
    return result;
}
