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

void push_to_list(lk_list_t **begin, lk_list_t *node)
{
    node->previous = NULL;
    node->next = NULL;
    if ((*begin) == NULL) {
        (*begin) = node;
        return;
    } else {
        node->next = (*begin);
        (*begin)->previous = node;
        (*begin) = node;
    }
}
