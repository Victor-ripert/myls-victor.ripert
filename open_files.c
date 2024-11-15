/*
** EPITECH PROJECT, 2024
** open_files
** File description:
** boucle opendir
*/
#include "my.h"
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

int node_len(node_t files)
{
    node_t tmp;
    int count = 1;

    tmp = files;
    while (tmp->next != NULL) {
	count ++;
	tmp->next;
    }
    return count;
}

node_t open_files(node_t files)
{
    DIR *dirp;
    struct dirent *dp;
    node_t tmp = malloc(node_size);
    //int count = node_len(files);
    //node_t array[count];
    //int i = 0;

    tmp = files;
    while (tmp->next != NULL) {
	dirp = opendir(tmp->str);
	dir_processing(dirp);
	/*for (dp = readdir(dirp); dp != NULL; dp = readdir(dirp)) {
	    add_node(array[i], dp->d_name);
	    printf("%s\n", dp->d_name);
	}*/
	//i++;
	tmp = tmp->next;
    }
    return tmp;
}
