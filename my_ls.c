/*
** EPITECH PROJECT, 2024
** my_ls
** File description:
** act like ls command with alRdrt flags
*/
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdbool.h>
#include "my_ls.h"


param_t *init_param(void)
{
    param_t *params = malloc(sizeof(param_t) * 6);

    params[0].flag = 'a';
    params[0].present = 0;
    params[1].flag = 'l';
    params[1].present = 0;
    params[2].flag = 'R';
    params[2].present = 0;
    params[3].flag = 'd';
    params[3].present = 0;
    params[4].flag = 'r';
    params[4].present = 0;
    params[5].flag = 't';
    params[5].present = 0;
    return params;
}

int my_ls(int argc, char **argv)
{
    lk_list_t *list = NULL;
    int rev = 0;
    param_t *params = init_param();

    ls_flags(argc, argv, &params);
    files_to_list(argc, argv, &list, params);
    rev = params[4].present;
    select_sort(&list, rev);
    if (params[1].present == 1) {
        get_info(&list, params);
        display_list_l(list);
    } else {
        display_list(list);
    }
}
