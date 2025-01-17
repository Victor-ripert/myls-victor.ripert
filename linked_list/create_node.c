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

char *my_strcat(char *first, char *second)
{
    int size_1 = sizeof(char) * my_strlen(first);
    int size_2 = sizeof(char) * my_strlen(second);
    char *result = malloc(size_1 + size_2 + 1);
    int i = 0;

    for (int j = 0; j < my_strlen(first); j++) {
        result[i] = first[j];
        i++;
    }
    for (int k = 0; k < my_strlen(second); k++) {
        result[i] = second[k];
        i++;
    }
    result[i + 1] = '\0';
    return result;
}

lk_list_t *create_node(char *file, char *path)
{
    lk_list_t *node_list = malloc(sizeof(lk_list_t));
    info_t *node_info = malloc(sizeof(info_t));

    node_info->file = file;
    node_info->path = my_strcat(my_strcat(path, "/"), file);
    node_list->info = node_info;
    node_list->previous = NULL;
    node_list->next = NULL;
    return node_list;
}
