#include "my.h"
#include <stdlib.h>

node_info_t create_node_info(){
    node_info_t temp;
    temp = (node_info_t)malloc(sizeof(struct ls_info));
    temp->next = NULL;
    return temp;
}


