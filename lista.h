#ifndef PROJETOPPP_LISTAS_H
#define PROJETOPPP_LISTAS_H

#include "struct.h"

int dateMin(int month, int day, int hour, int min);
void printDate(int minutes, int *month, int *hour, int *day, int *min);
list create();
int isEmpty(list head);
list destroy(list head);
void search(list head, int min, list *prev, list *cur);
void delete(list head, int min);
void insert(list head, struct Data d);
void printList(list head);

#endif //PROJETOPPP_LISTAS_H
