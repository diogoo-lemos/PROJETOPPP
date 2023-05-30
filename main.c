#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"

int main()
{
    char operation[10];
    int loop_state = 1;
    list head = create();
    FILE *fp;

    while (loop_state)
    {
        printf("Indique a operação: \n");
        scanf("%s", operation);
        getchar(); // Consome o \n

        if (strcmp(operation, "RESERVAR") == 0)
        {
            // Fazer uma reserva
            char str[25];
            char name[10];
            char type[2];
            int month, day, hour, min;
            printf("Introduza o nome, tipo e data da marcação no seguinte formato: Nome/tipo(l para lavagem, m para marcação) DD/MM HH:MM\n");
            fgets(str, 25, stdin);
            int a = sscanf(str, "%[^/]/%[^ ] %d/%d %d:%d", name, type, &day, &month, &hour, &min);
            if(a != 6)
            {
                printf("Formato introduzido errado ou erro na leitura.\n");
            }
            else if((min != 0  && min != 30) || 8 > hour || hour >= 18)
            {
                printf("hour: %d", hour);
                printf("minutes: %d", min);
                printf("Horário inválido.\n");
            }
            else if(strcmp(type, "m") == 0 && hour == 17 && min == 30)
            {
                printf("Horário inválido.\n");
            }
            else
            {
                struct Data d;
                d.mins = dateMin(month, day, hour, min);
                strcpy(d.name, name);
                strcpy(d.type, type);
                insert(head, d);
            }
        }
        else if (strcmp(operation, "CANCELAR") == 0)
        {
            // Cancelar uma reserva
            char str[25];
            int month, day, hour, min;

            printf("Introduza a data e hora da marcação no seguinte formato: DD/MM HH:MM\n");
            fgets(str, 25, stdin);
            int a = sscanf(str, "%d/%d %d:%d", &day, &month, &hour, &min);
            if(a != 4)
            {
                printf("Formato introduzido errado ou erro na leitura.\n");
            }
            else
            {
                delete(head, dateMin(month, day, hour, min));
                printf("Marcação cancelada.\n");
            }

        }
        else if (strcmp(operation, "LISTAR") == 0)
        {
            // Listar todas as marcações
            printf("Lista de marcações:\n");
            printList(head);
        }
        else if (strcmp(operation, "LISTAR_CLIENTE") == 0)
        {
            // Listar todas as marcações de um cliente.
            char name[10];
            printf("Introduza um nome:\n");
            scanf("%s", name);

            list aux = head->next;
            int month, day, hour, min;
            while(aux)
            {
                if(strcmp(aux->d.name, name) == 0)
                {
                    printf("Tipo: %s - ", aux->d.type);
                    printDate(aux->d.mins, &month, &day, &hour, &min);
                }
                if(aux->prev != NULL)
                {
                    list prev = aux->prev;
                    while(prev)
                    {
                        printf("Pré-reserva - Tipo: %s - Data: ", prev->d.type);
                        printDate(prev->d.mins, &month, &day, &hour, &min);
                        prev = prev->prev;
                    }
                }
                aux = aux->next;
            }
        }
        else if (strcmp(operation, "CONCLUIR") == 0)
        {
            // Concluir uma lavagem ou manutenção
            conclude(head);
            printf("Lavagem mais recente concluída.\n");
        }
        else if (strcmp(operation, "CARREGAR") == 0)
        {
            // Lê informação de um ficheiro
            fp = fopen("data.txt", "r");
            if(fp != NULL)
            {
                char str[25];
                struct Data d;
                while(fgets(str, 25, fp) != NULL)
                {
                    char name[10];
                    char type[2];
                    int month, day, hour, min;

                    sscanf(str, "%s %d %d %d %d %s", name, &day, &month, &hour, &min, type);
                    d.mins = dateMin(month, day, hour, min);
                    strcpy(d.name, name);
                    strcpy(d.type, type);
                    insert(head, d);
                }
            }
            else
            {
                printf("Ficheiro não existe, nada para carregar.\n");
            }
            fclose(fp);
        }
        else if (strcmp(operation, "GUARDAR") == 0)
        {
            // Guarda informação num ficheiro.
            fp = fopen("data.txt", "w");
            if(fp != NULL)
            {
                int m = 0;
                int d = 0;
                int h = 0;
                int mn = 0;

                list aux = head->next;

                printf("Marcações a carregar:\n");
                while(aux)
                {
                    printDate(aux->d.mins, &m, &d, &h, &mn);
                    fprintf(fp, "%s %d %d %d %d %s\n", aux->d.name, d, m, h, mn, aux->d.type);
                    aux = aux->next;
                }
                printf("Dados carregados.\n");
                fclose(fp);
            }
        }
        else if (strcmp(operation, "SAIR") == 0)
        {
            destroy(head);
            printf("A sair do programa...\n");
            loop_state = 0;
        }
        else
        {
            printf("Operação não existente.\n");
        }
    }
    return 0;
}
