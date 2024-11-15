/*
** EPITECH PROJECT, 2024
** files_loop
** File description:
** files loop
*/
#include "my.h"
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

int files_loop(node_t files, ls_flag_t flags_tab[])
{
    DIR *dirp;
    struct dirent *dp;
    node_t tmp;

    print_node(files);
    tmp = files;
    while (tmp != NULL) {
	dirp = opendir(tmp->str);
	dir_processing(dirp, flags_tab, tmp->str);
	tmp = tmp->next;
	closedir(dirp);
    }
    return 0;
}
