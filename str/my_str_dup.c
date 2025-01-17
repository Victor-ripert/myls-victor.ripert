/*
** EPITECH PROJECT, 2024
** print_typed_value.c
** File description:
** display the value of void * in function of is type passed as argument
*/
#include <stdio.h>
#include <stdlib.h>
#include "my_ls.h"

char *my_str_dup(char *str)
{
    int str_len = my_strlen(str);
    char *result = malloc(sizeof(char) * (str_len + 1));

    for (int i = 0; i < str_len; i++) {
        result[i] = str[i];
    }
    result[str_len] = '\0';
    return result;
}
