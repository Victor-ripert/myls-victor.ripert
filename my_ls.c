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

void array_add(char **array)
{
    int i = 0;
    char **array_cpy;

    while (array[i] != NULL) {
	i++;
    }
    array_cpy = malloc(sizeof(char) + (sizeof(char) * i));
    for (int n = 0; n != i; n++) {
	array_cpy[n] = array[n];
    }
}

int my_ls(int argc, char **argv)
{
    DIR *dirp;
    struct dirent *dp;
    struct stat sb;
    char *flags[0];
    char *files[0];
    int n = 0;
    int z = 0;

    if (argc == 1) {
	files[0] = ".";
    } else {
	for (int i = 1; i != argc; i++) {
	    if (argv[i][0] == '-') {
		array_add(flags);
		flags[n] = argv[i];
		n++;
	    } else {
		array_add(files);
		files[z] = argv[i];
		z ++;
	    }
	}
    }
    //printf("%s\n", files[0]);
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
