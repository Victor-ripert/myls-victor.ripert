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
#include "my.h"

int flag_tri(char *str)
{
    for (int i = 0; flags_tab[i].flag != '.'; i++) {
	for (int n = 1; str[n] != '\0'; n++) {
	    if (str[n] == flags_tab[i].flag) {
		flags_tab[i].present = true;
	    }
	}
    }
    return 0;
}

int my_ls(int argc, char **argv)
{
    DIR *dirp;
    struct dirent *dp;
    struct stat sb;
    node_t files = malloc(sizeof(node_t));
    //node_t files_open = malloc(node_size);
    int count = 0;

    if (argc == 1) {
	files->str = ".";
	files->next = NULL;
    } else {
	for (int i = 1; i != argc; i++) {
	    if (argv[i][0] == '-') {
		flag_tri(argv[i]);
	    } else {
		add_node(files, argv[i]);
		count ++;
	    }
	}
    }
    if (count == 0) {
	files->str = ".";
	files->next = NULL;
    }
    files_loop(files, flags_tab);
    //open_files(files);
    //print_node(files_open);
/*
    dirp = opendir(".");
    for (dp = readdir(dirp); dp != NULL;dp = readdir(dirp)) {
	printf("%s : ", dp->d_name);
	lstat(dp->d_name, &sb);
	printf("%ld, ", sb.st_size);
	printf("\n");
    }
    closedir(dirp);
*/
    return 0;
}
