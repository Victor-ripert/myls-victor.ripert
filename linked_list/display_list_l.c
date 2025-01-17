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

int find_total_size(lk_list_t *begin)
{
    lk_list_t *temp;
    int size = 0;

    temp = begin;
    while (temp != NULL) {
        size += temp->info->size;
        temp = temp->next;
    }
    return size;
}

void display_part1(lk_list_t *temp)
{
    my_putstr(temp->info->permission);
    my_putstr(" ");
    my_put_nbr(temp->info->nb_link);
    my_putstr(" ");
    my_putstr(temp->info->owner);
    my_putstr(" ");
    my_putstr(temp->info->group);
    my_putstr(" ");
    my_put_nbr(temp->info->size);
    my_putstr(" ");
}

void display_part2(lk_list_t *temp)
{
    my_putstr(temp->info->modi);
    my_putstr(" ");
    my_putstr(temp->info->file);
    my_putstr("\n");
}

void display_list_l(lk_list_t *begin)
{
    lk_list_t *temp;

    printf("total %d\n", find_total_size(begin));
    temp = begin;
    while (temp != NULL) {
        display_part1(temp);
        display_part2(temp);
        temp = temp->next;
    }
}
