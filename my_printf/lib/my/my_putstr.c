/*
** EPITECH PROJECT, 2024
** my_putstr
** File description:
** display one by one characters of a string
*/
#include "flags.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        my_putchar(str[i]);
        i++;
    }
    return i;
}
