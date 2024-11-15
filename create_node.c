/*
** EPITECH PROJECT, 2024
** create_node
** File description:
** create node
*/
#include "my.h"
#include <stdlib.h>

node_t create_node(){
    node_t temp;
    temp = (node_t)malloc(sizeof(struct ls_file));
    temp->next = NULL;
    return temp;
}
