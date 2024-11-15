/*
** EPITECH PROJECT, 2024
** .
** File description:
** .
*/
#include <stdlib.h>
#include "my.h"

node_info_t add_node_info(node_info_t head, char **value)
{
    node_info_t temp;
    node_info_t p;
    temp = create_node_info();
    temp->tab = value;
    if (head == NULL) {
        head = temp;
    } else if (head->tab == NULL) {
        head->tab = value;
    } else {
        p = head;
        while(p->next != NULL) {
            p = p->next;
        }
        p-> next = temp;
    }
    return head;
}

