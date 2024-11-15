/*
** EPITECH PROJECT, 2024
** print_node
** File description:
** print node
*/
#include <stdlib.h>
#include "my.h"
#include <stdio.h>

int print_node(ls_file_t *file)
{
    ls_file_t *temp;

    temp = file;
    while (temp->next != NULL) {
        printf("str = %s\n", temp->str);
        temp = temp->next;
    }
    printf("data = %s\n", temp->str);
    return 0;
}
