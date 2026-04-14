#include <stdio.h>
#include "pilha.h"
#include <stdlib.h>
#include <time.h>

/*=========================================================
    Função para inicializar a pilha
    Parametros: 
        1 - pilha - ponteiro para a struct com os dados da pilha
  =========================================================*/
void inicializarPilha(TPilha * const pilha){
    pilha->tamanho = 0;
    pilha->topo = NULL;
}

/*=========================================================
    Função que verifica se a pilha está vazia
    Parametros: 
        1 - pilha - ponteiro para a struct com os dados da pilha
    Retorno:
        != 0   - pilha está vazia
        0      - pilha não está vazia
  =========================================================*/
int pilhaEstaVazia(TPilha const * const pilha){
    if (pilha == NULL || pilha->topo == NULL) {
        return 1;
    }
    return 0;
}

/*=========================================================
    Função para acessar o topo da pilha
    Parametros: 
        1 - pilha - ponteiro para a struct com os dados da pilha
    Retorno:
        valor do elemento no topo da pilha
  =========================================================*/
int acessarPilha(TPilha const * const pilha){
    if(pilhaEstaVazia(pilha)){
        printf("Pilha vazia!\n");
        return -1;
    }

    return pilha->topo->dado;
}

/*=========================================================
    Função para inserir um elemento na pilha
    Parametros: 
        1 - pilha    - ponteiro para a struct com os dados da pilha
        2 - elemento - valor a ser inserido na pilha
  =========================================================*/
void empilhar(TPilha * const pilha, int elemento){
    TNo * const pNO = malloc(sizeof(TNo));
    if(pNO == NULL){
        printf("Erro ao alocar memoria!\n");
        return;
    }
    //original
    pNO->dado = elemento;
    pNO->proximo = pilha->topo;

    //copia
    pNO->copia = elemento;

    // topo apontando pro endereço onde foi guardado o elemento
    pilha->topo = pNO;
    pilha->tamanho++;

}

/*=========================================================
    Função para remover um elemento da pilha
    Parametros: 
        1 - pilha - ponteiro para a struct com os dados da pilha
  =========================================================*/
void desempilhar(TPilha  * const pilha){
    if(pilhaEstaVazia(pilha)){
        printf("Pilha vazia!\n");
        return;
    }
    TNo * const pAux = pilha->topo; // onde está o endereço do nó a ser liberado
    pilha->topo = pAux->proximo;
    pilha->tamanho--;
    free(pAux);
}

/*=========================================================
    Função que libera o espaço de memória usado pela pilha
    Parametros: 
        1 - pilha - ponteiro para a struct com os dados da pilha
  =========================================================*/
void liberarPilha(TPilha * const pilha){
    while(!pilhaEstaVazia(pilha)){
        desempilhar(pilha);
    }
}

/*=========================================================
    Função para mostrar os elementos da pilha
    Parametros: 
        1 - pilha - ponteiro para a struct com os dados da pilha
  =========================================================*/
void mostrarPilha(TPilha const * const pilha){
    if(pilhaEstaVazia(pilha)){
        printf("Pilha = { }\n");
        return;
    }

    printf("Pilha = { ");

    TNo *atual = pilha->topo;

    while(atual != NULL){
        printf("%d", atual->dado);
        
        if(atual->proximo != NULL){
            printf(", ");
        }
        
        atual = atual->proximo;
    }

    printf(" }\n");
}

/*=========================================================
    Função para preencher a pilha com elementos aleatorios de 0 a 50
     Parametros: 
        1 - pilha - ponteiro para a struct com os dados da pilha
        2 - quantidade - número de elementos a serem inseridos
  =========================================================*/
void preencherPilha(TPilha * const pilha, int quantidade){
    srand(time(NULL));
    for(int i = 0; i < quantidade; i++){
        int elemento = rand() % 51;
        empilhar(pilha, elemento);
    }
}

/*=========================================================
    Função para ordenar a pilha usando o método de ordenação usando pilha
     Parametros: 
        1 - pilha - ponteiro para a struct com os dados da pilha
  =========================================================*/
  //verificar se esta ordenando usando pilha
  void ordenarPilha(TPilha * const pilha){
    TPilha pilhaAuxiliar;
    inicializarPilha(&pilhaAuxiliar);

    while(!pilhaEstaVazia(pilha)){
        int temp = acessarPilha(pilha);
        desempilhar(pilha);

        while(!pilhaEstaVazia(&pilhaAuxiliar) && acessarPilha(&pilhaAuxiliar) > temp){
            empilhar(pilha, acessarPilha(&pilhaAuxiliar));
            desempilhar(&pilhaAuxiliar);
        }

        empilhar(&pilhaAuxiliar, temp);
    }

    while(!pilhaEstaVazia(&pilhaAuxiliar)){
        empilhar(pilha, acessarPilha(&pilhaAuxiliar));
        desempilhar(&pilhaAuxiliar);
    }
}