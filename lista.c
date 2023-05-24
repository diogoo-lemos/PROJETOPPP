#include <stdio.h>
#include <stdlib.h>

#include "struct.h"

int days_per_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Converts a date to minutes
int dateMin(int month, int day, int hour, int min)
{
    int minutes = 0;

    // Number of minutes in the months
    for (int i = 0; i < month - 1; i++)
    {
        minutes += days_per_month[i] * 24 * 60;
    }

    minutes += (day - 1) * 24 * 60; // Days
    minutes += hour * 60;           // Hours
    minutes += min;                 // Remaining minutes

    return minutes;
}

// Converts minutes to date and prints it
void printDate(int minutes)
{
    int aux_minutes = minutes;
    int month, hour, day, min;

    // Get month
    int i = 0;
    while (aux_minutes >= days_per_month[i] * 24 * 60)
    {
        aux_minutes -= days_per_month[i] * 24 * 60;
        i++;
    }
    month = i + 1;

    // Get day
    i = 1;
    while (aux_minutes >= 24 * 60)
    {
        aux_minutes -= 24 * 60;
        i++;
    }
    day = i;

    // Get hour
    i = aux_minutes / 60;
    aux_minutes -= i * 60;
    hour = i;

    // Get min
    min = aux_minutes;

    if(min == 0)
    {
        printf("%d/%d %d:%d0\n", day, month, hour, min);
    }
    else
    {
        printf("%d/%d %d:%d\n", day, month, hour, min);
    }
    
}

// Creates doubly linked list
list create()
{
    list aux;
    struct Data d = {"", "", 0};
    aux = (list)malloc(sizeof(Node));

    if (aux != NULL)
    {
        aux->d = d;
        aux->next = NULL;
        aux->prev = NULL;
    }
    return aux;
}

// Checks if the list is empty
int isEmpty(list head)
{
    if (head->next == NULL)
        return 1; // Retruns 1 if empty
    else
        return 0; // Returns 0 if not
}

// Destroys the list and frees the space
list destroy(list head)
{
    list temp;
    while (!isEmpty(head))
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    free(head);
    return NULL;
}

// Searches for a place to insert a new node
void search(list head, int min, list *prev, list *cur)
{
    *prev = head;
    *cur = head->next;

    while((*cur) != NULL && (*cur)->d.mins < min)
    {
        *prev = *cur;
        *cur = (*cur)->next;
    }
    if((*cur) != NULL && (*cur)->d.mins != min)
    {
        *cur = NULL;
    }
}

// Deletes a node
void delete(list head, int min)
{
    list prev, cur, next;
    search(head, min, &prev, &cur);
    next = cur->next;
    if(cur != NULL)
    {
        prev->next = cur->next;
        next->prev = cur->prev;
        free(cur);
    }
}

// Inserts a node
void insert(list head, struct Data d)
{
    list node, prev, cur, next;
    node = (list)malloc(sizeof(Node));
    if(node != NULL)
    {
        node->d = d;
        search(head, d.mins, &prev, &cur);
        next = prev->next;
        
        if(next != NULL)
        {
            node->next = next;
            node->prev = prev;
            prev->next = node;
            next->prev = node;
        }
        else
        {
            prev->next = node;
            node->prev = prev;
            node->next = NULL;
        }
    }
}

// Prints every data stored on the list
void printList(list head)
{
    list aux = head->next;
    int i = 0;
    while(aux)
    {
        printf("Nome: %s - Tipo: %s - Data: ", aux->d.name, aux->d.type);
        printDate(aux->d.mins);
        aux = aux->next;
    }
}