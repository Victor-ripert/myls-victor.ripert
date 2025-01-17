/*
** EPITECH PROJECT, 2024
** print_typed_value.c
** File description:
** display the value of void * in function of is type passed as argument
*/
#include <stdio.h>
#include <stdlib.h>
#include "my_ls.h"

void replace_ptr(lk_list_t **temp, lk_list_t **begin)
{
    if ((*temp)->previous != NULL) {
        (*temp)->previous->next = (*temp)->next;
    } else {
        *begin = (*temp)->next;
    }
    if ((*temp)->next != NULL) {
        (*temp)->next->previous = (*temp)->previous;
    }
}
