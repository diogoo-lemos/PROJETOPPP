#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"

int main()
{
    char operation[10];
    int loop_state = 1;

    printf("Indique a operação: \n");
    while (loop_state)
    {
        scanf("%s", operation);

        if (strcmp(operation, "RESERVAR") == 0)
        {
            // Fazer uma reserva
        }
        else if (strcmp(operation, "CANCELAR") == 0)
        {
            // Cancelar uma reserva
        }
        else if (strcmp(operation, "LISTAR_M") == 0)
        {
            // Listar todas as marcações
        }
        else if (strcmp(operation, "LISTAR_CLIENTE") == 0)
        {
            // Listar todas as marcações de um cliente
        }
        else if (strcmp(operation, "CONCLUIR") == 0)
        {
            // Concluir uma lavagem ou manutenção
        }
        else if (strcmp(operation, "CARREGAR") == 0)
        {
            // Lê informação de um ficheiro
        }
        else if (strcmp(operation, "GUARDAR") == 0)
        {
            // Guarda informação num ficheiro
        }
        else if (strcmp(operation, "SAIR") == 0)
        {
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
