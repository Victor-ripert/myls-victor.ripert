/*
** EPITECH PROJECT, 2024
** add_node
** File description:
** add_node
*/
#include <stdlib.h>
#include "my.h"

node_t add_node(node_t head, char *value)
{
    node_t temp;
    node_t p;
    temp = create_node();
    temp->str = value;
    if (head == NULL) {
        head = temp;
    } else if (head->str == NULL) {
	head->str = value;
    } else {
        p = head;
	while(p->next != NULL) {
            p = p->next;
        }
        p-> next = temp;
    }
    return head;
}
