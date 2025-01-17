/*
** EPITECH PROJECT, 2024
** print_typed_value.c
** File description:
** display the value of void * in function of is type passed as argument
*/
#include <stdio.h>
#include <stdlib.h>
#include "my_ls.h"

void swap_in_list(lk_list_t **first_node, lk_list_t **second_node)
{
    info_t *temp;

    temp = (*first_node)->info;
    (*first_node)->info = (*second_node)->info;
    (*second_node)->info = temp;
}
