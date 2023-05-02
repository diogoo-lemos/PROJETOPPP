#ifndef PROJETOPPP_STRUCT_H
#define PROJETOPPP_STRUCT_H

typedef struct list_node{
    char name[50];
    char type[2];
    double min;
    double hour;
    double day;
    double month;
    int num;
    struct list_node *next;

}list_node;

typedef struct list_pr_node{
    struct list_node ln;
    struct list_pr_node *next;
}list_pr_node;

#endif //PROJETOPPP_STRUCT_H
