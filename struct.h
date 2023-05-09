#ifndef PROJETOPPP_STRUCT_H
#define PROJETOPPP_STRUCT_H

typedef struct data{
    char name[50];
    char type[2];
    int month;
    int day;
    int hour;
    int min;
}data;

typedef struct list_node{
    data d;
    struct list_node *next;

}list_node;

typedef list_node *List;

#endif //PROJETOPPP_STRUCT_H
