/*
** EPITECH PROJECT, 2024
** .
** File description:
** .
*/
#include "my.h"
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

int print_node_info_l(ls_info_t *file)
{
    ls_info_t *temp;

    temp = file;
    while (temp != NULL) {
	printf("%s ", temp->tab[0]);
	printf("%s ", temp->tab[1]);
	printf("%s ", temp->tab[2]);
	printf("%s ", temp->tab[3]);
	printf("%s ", temp->tab[4]);
	printf("%s ", temp->tab[5]);
	printf("%s\n", temp->tab[6]);
	temp = temp->next;
    }
    return 0;
}
