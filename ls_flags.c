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

void find_flag(char flag, param_t **params)
{
    for (int j = 0; j < 6; j++) {
        if (flag == (*params)[j].flag) {
            (*params)[j].present = 1;
        }
    }
}

void flags_to_param(char *flags, param_t **params)
{
    for (int i = 0; flags[i] != '\0'; i++) {
        find_flag(flags[i], params);
    }
}

void ls_flags(int argc, char **argv, param_t **params)
{
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            flags_to_param(argv[i], params);
        }
    }
}
