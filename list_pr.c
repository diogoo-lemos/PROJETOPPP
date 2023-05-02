#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "list_pr.h"

void search_element(list_node **list, int key, list_node **prev, list_node **cur) {
    prev = NULL;
    *cur = *list;

    while ((*cur) != NULL && (*cur)->num < key) {
        *prev = *cur;
        *cur = (*cur)->next;
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