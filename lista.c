#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// Converts minutes to date and prints it (also updates the date variables passed)
void printDate(int minutes, int *month, int *hour, int *day, int *min)
{
    int aux_minutes = minutes;

    // Get month
    int i = 0;
    while (aux_minutes >= days_per_month[i] * 24 * 60)
    {
        aux_minutes -= days_per_month[i] * 24 * 60;
        i++;
    }
    *month = i + 1;

    // Get day
    i = 1;
    while (aux_minutes >= 24 * 60)
    {
        aux_minutes -= 24 * 60;
        i++;
    }
    *day = i;

    // Get hour
    i = aux_minutes / 60;
    aux_minutes -= i * 60;
    *hour = i;

    // Get min
    *min = aux_minutes;

    if(*min == 0)
    {
        printf("%d/%d %d:%d0\n", *day, *month, *hour, *min);
    }
    else
    {
        printf("%d/%d %d:%d\n", *day, *month, *hour, *min);
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

    if(min != 0)
    {
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
}

// Deletes a node
void delete(list head, int min)
{

    list prev, cur, next, pre;
    search(head, min, &prev, &cur);
    if(cur != NULL)
    {
        next = cur->next;
        pre = cur->prev;

        if(pre != NULL)
        {
            if(next != NULL)
            {
                prev->next = pre;
                pre->next = next;
            }
            else
            {
                prev->next = pre;
                pre->next = NULL;
            }
        }
        else if(next != NULL)
        {
            prev->next = next;
        }
        else
        {
            prev->next = NULL;
        }
        free(cur);
    }
}

// Liberta o primeiro nó da lista
void conclude(list head)
{
    list temp = head->next;
    if(temp != NULL)
    {
        list next = temp->next;
        if(next != NULL)
        {
            head->next = next;
        }
        else
        {
            head->next = NULL;
        }
        free(temp);
    }
}

// Inserts a node
void insert(list head, struct Data d)
{
    list node, prev, cur, next;
    int diff = 0;
    int diff2 = 0;
    node = (list)malloc(sizeof(Node));
    if(node != NULL)
    {
        node->d = d;
        search(head, d.mins, &prev, &cur);

        if(strcmp(node->d.type, "l") == 0)
        {
            diff = 30;  // Tempo de uma lavagem
        }
        else
        {
            diff = 60;  // Tempo de uma manutenção
        }

        if(strcmp(prev->d.type, "l") == 0)
        {
            diff2 = 30;  // Tempo de uma lavagem
        }
        else
        {
            diff2 = 60;  // Tempo de uma manutenção
        }

        next = prev->next;

        if(next != NULL)
        {
            if(next->d.mins - node->d.mins < diff)
            {
                printf("Horário ocupado, guardar pré-reserva.\n");
                list temp, temp2;
                temp = next->prev;
                temp2 = NULL;
                while(temp != NULL)
                {
                    temp2 = temp;
                    temp = temp->prev;
                }
                if(temp2 == NULL)
                {
                    temp2 = next;
                }
                node->next = temp2;
                node->prev = NULL;
                temp2->prev = node;

            }
            else if(node->d.mins - prev->d.mins < diff2)
            {
                printf("Horário ocupado, guardar pré-reserva.\n");
                list temp, temp2;
                temp = prev->prev;
                temp2 = NULL;
                while(temp != NULL)
                {
                    temp2 = temp;
                    temp = temp->prev;
                }
                if(temp2 == NULL)
                {
                    temp2 = prev;
                }
                node->prev = temp2;
                node->prev = NULL;
                temp2->prev = node;
            }
            else
            {
                node->next = next;
                node->prev = NULL;
                prev->next = node;
                next->prev = NULL;
            }
        }
        else
        {
            if(node->d.mins - prev->d.mins < diff2)
            {
                printf("Horário ocupado, guardar pré-reserva.\n");
                list temp, temp2;
                temp = prev->prev;
                temp2 = NULL;
                while(temp != NULL)
                {
                    temp2 = temp;
                    temp = temp->prev;
                }
                if(temp2 == NULL)
                {
                    temp2 = prev;
                }
                node->prev = temp2;
                node->prev = NULL;
                temp2->prev = node;
            }
            else
            {
                prev->next = node;
                node->prev = NULL;
                node->next = NULL;
            }
        }
    }
}

// Prints every data stored on the list
void printList(list head)
{
    list aux = head->next;
    int month, day, hour, min;
    int i = 0;
    while(aux)
    {
        printf("Nome: %s - Tipo: %s - Data: ", aux->d.name, aux->d.type);
        printDate(aux->d.mins, &month, &day, &hour, &min);
        
        if(aux->prev != NULL)
        {
            list prev = aux->prev;
            while(prev)
            {
                printf("Pré-reserva - Nome: %s - Tipo: %s - Data: ", prev->d.name, prev->d.type);
                printDate(prev->d.mins, &month, &day, &hour, &min);
                prev = prev->prev;
            }
        }
        aux = aux->next;
    }
}