/*
** EPITECH PROJECT, 2024
** dir_processing
** File description:
** processing the informations from dir and flags
*/
#include "my.h"
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

int dir_processing(DIR *dirp, ls_flag_t flags_tab[], char *dir_name)
{
    struct dirent *dp;
    node_t name_files = malloc(node_size);
    node_info_t stockage;
    //node_info_t sorted_stockage;

    if (flags_tab[2].present == true) {
	//ls_flag_r_maj(dirp);
    } else {
	for (dp = readdir(dirp); dp != NULL; dp = readdir(dirp)) {
	    if (dp->d_name[0] != '.') {
		add_node(name_files, dp->d_name);
	    } else if (flags_tab[1].present == true) {
		add_node(name_files, dp->d_name);
	    }
	}
	stockage = file_info_process(name_files, dir_name);
	//sorted_stockage = sort_stocked_info(stockage, flags_tab);
	if (flags_tab[3].present == true) {
	    print_node_info_l(stockage);
	} else {
	    print_node_info(stockage);
	}
    }
    return 0;
}
