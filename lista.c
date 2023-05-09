#include <stdlib.h>

#include "struct.h"

void search_element(List list, int month, int day, int hour, int min, List *prev, List *cur) {
    *prev = list;
    *cur = list->next;

    while ((*cur) != NULL && (*cur)->d.month < month) {
        *prev = *cur;
        *cur = (*cur)->next;
    }
    while ((*cur) != NULL && (*cur)->d.day < day) {
        *prev = *cur;
        *cur = (*cur)->next;
    }
    while ((*cur) != NULL && (*cur)->d.hour < hour) {
        *prev = *cur;
        *cur = (*cur)->next;
    }
    while ((*cur) != NULL && (*cur)->d.min < min) {
        *prev = *cur;
        *cur = (*cur)->next;
    }
    if ((*cur) != NULL && ((*cur)->d.month != month || (*cur)->d.day != day || (*cur)->d.hour != hour || (*cur)->d.min != min))
        *cur = NULL; /* elemento não encontrado*/
}

void insert(List list, char name, char type, double min, double hour, double day, double month, int num){
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
        printf("Name: %s, Time: %lf:%lf %lf/%lf \n", list->name, list->hour, list->min, list->day, list->month);
        list = list->next;
    }
}

void sort_new(list_node *list){
    
    // 0 --> while(1)
    // 1 --> dar loop pela lista
    
    //função para comparar as datas
    //  int date_compare(DATE *t1, DATE *t2) {
    // returns 1 if t1 greater than t2, -1 if t1 < t2, 0 if equal
    
    //if (t1->month > t2->month) return(1);
    //if (t1->month < t2->month) return(-1);
    
    // month aslo matches. so check day
    
    //if (t1->day > t2->day) return(1);
    //if (t1->day < t2->day) return(-1);
    
    // day also matches
    //return(0);
    
    //2 --> comparar a data de prev com a next
    //3 --> se for maior trocar
    
}
        
void sort_old(list_node *list){
    
    //0 --> while(1)
    //1 --> dar loop pela lista 
    //2 --> comparar usando a função date_compare
    //3 --> se for menor trocar
}
