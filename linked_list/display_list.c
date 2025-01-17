/*
** EPITECH PROJECT, 2024
** print_typed_value.c
** File description:
** display the value of void * in function of is type passed as argument
*/
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "my_ls.h"

void display_list(lk_list_t *begin)
{
    lk_list_t *temp;

    temp = begin;
    while (temp != NULL) {
        my_putstr(temp->info->file);
        my_putstr(" ");
        temp = temp->next;
    }
    printf("\n");
}
