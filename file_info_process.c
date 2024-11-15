/*
** EPITECH PROJECT, 2024
** files informations processing
** File description:
** get the information of the files
*/
#include "my.h"
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

//Stocker info et appeler fonction pour trie et display

static int display_info(char *pathname, char *name)
{
    struct stat sb;

    if (lstat(pathname, &sb) == -1) {
	printf("EXIT_FAILURE");
    }
    printf("right ");
    printf("%d ", (int)sb.st_nlink);
    printf("owner ");
    printf("group ");
    printf("%d ", (int)sb.st_size);
    printf("%d ", (int)sb.st_mtime);
    printf("%s\n", name);
    return 0;
}

/*
char *nbr_to_str(int nb)
{
    int b;

    while (nb / 10) {
	
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb / 10) {
        my_put_nbr(nb / 10);
    }
    b = nb % 10;
    my_putchar(b + '0');
    return 1;
}
*/


static char **stock_info(char *pathname, char *name)
{
    struct stat sb;
    char **info = malloc(sizeof(char *) * 7);

    if (lstat(pathname, &sb) == -1) {
	printf("EXIT_FAILURE");
    }
    info[0] = "right ";
    info[1] = nbr_to_str((int)sb.st_nlink);
    info[2] = "owner ";
    info[3] = "group ";
    info[4] = nbr_to_str((int)sb.st_size);
    info[5] = nbr_to_str((int)sb.st_mtime);
    info[6] = name;

    return info;
}

int str_len(char *str)
{
    int i = 0;
    
    while  (str[i] != '\0') {
	i++;
    }
    return i;
}

char *pathname_create(char *dir_name, char *file_name)
{
    int dir_len = str_len(dir_name);
    int file_len = str_len(file_name);
    char *result = malloc(1 + (sizeof(char) * (dir_len + file_len)));
    int i = 0;

    while (i != dir_len) {
	result[i] = dir_name[i];
	i++;
    }
    result[i] = '/';
    i++;
    file_len = file_len + dir_len;
    for (int n = 0; i != file_len + 1; n++) {
	result[i] = file_name[n];
	i++;
    }
    return result;
}

node_info_t file_info_process(node_t name_files, char *dir_name)
{
    node_t tmp;
    char *path_name;
    node_info_t stockage = malloc(sizeof(struct ls_info));

    tmp = name_files;
    while (tmp != NULL) {
	path_name = pathname_create(dir_name, tmp->str);
        add_node_info(stockage, stock_info(path_name, tmp->str));
        tmp = tmp->next;
    }
    return stockage;
}
