#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


int main(){
    int operation;
    printf("Indique a operação: \n");
    printf("0: Fechar o programa \n");
    while(1){
        scanf("%d", &operation);

        switch(operation){
            case(0):
                printf("A fechar o programa...");
                return 1;

            case(1):
                printf("Escreva o conteúdo da sua reserva: ");

            case(5):
                printf("A imprimir reservas...");

        }
    }
}
