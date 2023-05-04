#ifndef PROJETOPPP_LISTAS_H
#define PROJETOPPP_LISTAS_H

#include "structs.h"

void search_element()list_node **list, int key, list_node **prev, list_node **cur);
void insert(list_node **list, char nome, char tipo, char time, int num);
void remove_element(list_node **list, int key);
void print_list(list_node *list);


#endif //PROJETOPPP_LISTAS_H

