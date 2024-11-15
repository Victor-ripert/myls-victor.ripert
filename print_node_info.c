/*
** EPITECH PROJECT, 2024
** .
** File description:
** ;.
*/
#include <stdlib.h>
#include "my.h"
#include <stdio.h>

int print_node_info(ls_info_t *file)
{
    ls_info_t *temp;

    temp = file;
    while (temp != NULL) {
        printf("%s\n", temp->tab[6]);
        temp = temp->next;
    }
    return 0;
}
