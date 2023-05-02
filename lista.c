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