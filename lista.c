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

void insert(list_node **list, char name, char type, double min, double hour, double day, double month, int num){
   list_node *node = (list_node *)malloc(sizeof(list_node));
    list_node *prev, *cur;

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

void print_list(list_node *list){

    while(list != NULL){
        printf("Name: %s, Time: \n", list->name);
        list = list->next;
    }
}
