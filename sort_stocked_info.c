/*
** EPITECH PROJECT, 2024
** sort_stocked_info
** File description:
** sort_stocked info
*/
#include "my.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int node_info_len(node_info_t info)
{
    node_info_t tmp;
    int count = 0;

    tmp = info;
    while (tmp != NULL) {
	count ++;
	tmp = tmp->next;
    }
    return count;
}

char *lower_case(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
	if (str[i] < 97 && str[i] > 64) {
	    str[i] += 32;
	}
    }
    return str;
}

int str_sort(char *src1, char *src2)
{
    char *str1 = lower_case(src1);
    char *str2 = lower_case(src2);
    //printf("\n%d\n", total1 + total2);
    printf("str1 = %s\n", str1);
    printf("str2 = %s\n", str2);
    for (int i = 0; str1[i] != '\0' && str2[i] != '\0'; i++) {
	if (str1[i] < str2[i]) {
	    return 1;
	} else if (str1[i] > str2[i]) {
	    return 2;
	}
    }
    return 3;
}

char *last_sorted(node_info_t sorted)
{
    node_info_t tmp;
    char *last;

    tmp = sorted;
    while (tmp != NULL) {
	last = tmp->tab[6];
	tmp = tmp->next;
    }
    return last;
}

node_info_t alpha_sort(node_info_t info)
{
    node_info_t sorted = malloc(sizeof(struct ls_info));
    int info_len = node_info_len(info);
    node_info_t tmp;
    char *comparator;
    char **tab_comparator;
    int compare_result;

    sorted->tab = info->tab;
    for (int i = 0; i != info_len; i++)
    {
	tmp = info;
	comparator = last_sorted(sorted);
	while (tmp != NULL) {
	    compare_result = str_sort(tmp->tab[6], comparator);
	    printf("%d\n", compare_result);
	    if (compare_result == 1) {
		comparator = tmp->tab[6];
		//printf("%s\n", comparator);
		tab_comparator = tmp->tab;
		printf("tab comparator = %s\n", tab_comparator[6]);
	    }
	    tmp = tmp->next;
	}
	add_node_info(sorted, tab_comparator);
    }
    return sorted;
}

node_info_t sort_stocked_info(node_info_t info, ls_flag_t flags_tab[])
{
    node_info_t sorted_info = malloc(sizeof(struct ls_info));

    if (flags_tab[4].present == true) {
	printf("flag t");
    } else {
	sorted_info = alpha_sort(info);
    }
    return sorted_info;
}
