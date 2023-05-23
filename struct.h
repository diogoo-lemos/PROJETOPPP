#ifndef PROJETOPPP_STRUCT_H
#define PROJETOPPP_STRUCT_H

typedef struct Data{
    char name[50];
    char type[2]; // M para manutenção e L para lavagem
    int mins;
}Data;

typedef struct Node{
    struct list_node *prev;
    struct Data d;
    struct list_node *next;

}Node;

typedef Node *list;

#endif //PROJETOPPP_STRUCT_H
