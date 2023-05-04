#include <stdlib.h>
#include "struct.h"
#include "lista.h"

void search_element(list_node **list, int key, list_node **prev, list_node **cur) {
    prev = NULL;
    *cur = *list;

    while ((*cur) != NULL && (*cur)->num < key) {
        *prev = *cur;
        *cur = (*cur)->next;
    }
}

void insert(type_list_node **list, double num, type_list_operations *op){
    type_list_node *node = (type_list_node *)malloc(sizeof(type_list_node));
    type_list_node *prev, *cur;

    if(node != NULL){
        node->num = num;
        search_element(list, num, &prev, &cur);

        if(prev == NULL){
            node->next = cur;
            *list = node;
        }
        else{
            node->next = cur;
            prev->next = node;
        }
    }
}

void remove_element(list_node **list, int key) {
    list_node *prev, *cur;

    search_element(list, key, &prev, &cur);

    if (cur != NULL && cur->num == key) {
        if (prev == NULL) {
            *list = cur->next;
        } else {
            prev->next = cur->next;
        }
        free(cur);
    }
}
