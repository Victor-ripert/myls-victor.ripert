/*
** EPITECH PROJECT, 2024
** print_typed_value.c
** File description:
** display the value of void * in function of is type passed as argument
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_ls.h"

int sort_compare_rev(lk_list_t *min, lk_list_t *cur)
{
    int strcmp_result = 0;

    strcmp_result = my_strcmp(cur->info->file, min->info->file);
    if (strcmp_result > 0) {
        return 1;
    }
    return 0;
}

int sort_cmp_normal(lk_list_t *min, lk_list_t *cur)
{
    int strcmp_result = 0;

    strcmp_result = my_strcmp(cur->info->file, min->info->file);
    if (strcmp_result < 0) {
        return 1;
    }
    return 0;
}

int sort_cmp(lk_list_t *min, lk_list_t *cur, int rev)
{
    if (rev == 0) {
        return sort_cmp_normal(min, cur);
    } else {
        return sort_compare_rev(min, cur);
    }
}

lk_list_t **cmp_res(lk_list_t **cur, lk_list_t **min, int res_cmp)
{
    if (res_cmp == 1) {
        min = cur;
    }
    return min;
}

void select_sort(lk_list_t **head, int rev)
{
    lk_list_t **first_unsorted_node = head;
    lk_list_t **min = head;
    lk_list_t **cur = head;
    int result_compare = 0;

    while ((*first_unsorted_node) != NULL) {
        min = first_unsorted_node;
        while ((*cur) != NULL) {
            result_compare = sort_cmp((*min), (*cur), rev);
            min = cmp_res(cur, min, result_compare);
            cur = &(*cur)->next;
        }
        swap_in_list(first_unsorted_node, min);
        first_unsorted_node = &(*first_unsorted_node)->next;
        cur = first_unsorted_node;
    }
}
