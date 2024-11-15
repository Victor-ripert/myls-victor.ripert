/*
** EPITECH PROJECT, 2024
** my_strlen
** File description:
** return length of a str
*/
#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;
    int retoure = 0;

    while (str[i] != '\0'){
        i++;
        retoure++;
    }
    return (retoure);
}
