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

        if (strcmp(operation, "RESERVAR") == 0)
        {
            // Fazer uma reserva (unfinished)
        }
        else if (strcmp(operation, "CANCELAR") == 0)
        {
            // Cancelar uma reserva (unfinished)
        }
        else if (strcmp(operation, "LISTAR") == 0)
        {
            // Listar todas as marcações
            printf("Lista de marcações:\n");
            printList(head);
        }
        else if (strcmp(operation, "LISTAR_CLIENTE") == 0)
        {
            // Listar todas as marcações de um cliente (unfinished)
        }
        else if (strcmp(operation, "CONCLUIR") == 0)
        {
            // Concluir uma lavagem ou manutenção (unfinished)
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
            // Guarda informação num ficheiro (unfinished)
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
