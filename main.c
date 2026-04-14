#include <stdio.h>
#include "pilha.h"
#include <stdlib.h>

int main(void){
    TPilha pilha;
    inicializarPilha(&pilha);

    printf("Digite o tamanho da pilha: ");
    scanf("%d", &pilha.tamanho);

        preencherPilha(&pilha, pilha.tamanho);
        printf("Pilha antes da ordenacao:\n");
        mostrarPilha(&pilha);
    
        ordenarPilha(&pilha);
        printf("Pilha depois da ordenacao:\n");
        mostrarPilha(&pilha);
    
        liberarPilha(&pilha);

    system("pause");
    return 0;
}