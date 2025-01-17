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

char *find_dir(int argc, char **argv)
{
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-') {
            return argv[i];
        }
    }
    return ".";
}

void get_stat(lk_list_t **begin, char *dir, param_t *params)
{
    DIR *dirp;
    struct dirent *dp;

    dirp = opendir(dir);
    for (dp = readdir(dirp); dp != NULL; dp = readdir(dirp)) {
        if (dp->d_name[0] != '.' || params[0].present == 1) {
        push_to_list(begin, create_node(dp->d_name, dir));
        }
    }
}

void files_to_list(int argc, char **argv, lk_list_t **begin, param_t *params)
{
    char *dir = find_dir(argc, argv);

    if (params[3].present != 1) {
        get_stat(begin, dir, params);
    } else {
        push_to_list(begin, create_node(find_dir(argc, argv), dir));
    }
}
