
#ifndef PILHA_H
#define PILHA_H

typedef struct TNo TNo;
typedef struct TNo{
    int dado;
    int copia;
    TNo *proximo;
}TNo;

typedef struct{
    int tamanho;
    TNo *topo;
}TPilha;

/*=========================================================
    Função para inicializar a pilha
    Parametros: 
        1 - pilha - ponteiro para a struct com os dados da pilha
  =========================================================*/
void inicializarPilha(TPilha * const pilha);

/*=========================================================
    Função que verifica se a pilha está vazia
    Parametros: 
        1 - pilha - ponteiro para a struct com os dados da pilha
    Retorno:
        != 0   - pilha está vazia
        0      - pilha não está vazia
  =========================================================*/
int pilhaEstaVazia(TPilha const * const pilha);

/*=========================================================
    Função para acessar o topo da pilha
    Parametros: 
        1 - pilha - ponteiro para a struct com os dados da pilha
    Retorno:
        valor do elemento no topo da pilha
  =========================================================*/
int acessarPilha(TPilha const * const pilha);

/*=========================================================
    Função para inserir um elemento na pilha
    Parametros: 
        1 - pilha    - ponteiro para a struct com os dados da pilha
        2 - elemento - valor a ser inserido na pilha
  =========================================================*/
void empilhar(TPilha * const pilha, int elemento);

/*=========================================================
    Função para remover um elemento da pilha
    Parametros: 
        1 - pilha - ponteiro para a struct com os dados da pilha
  =========================================================*/
void desempilhar(TPilha * const pilha);
/*=========================================================
    Função que libera o espaço de memória usado pela pilha
    Parametros: 
        1 - pilha - ponteiro para a struct com os dados da pilha
  =========================================================*/
void liberarPilha(TPilha * const pilha);

/*=========================================================
    Função para mostrar os elementos da pilha
    Parametros: 
        1 - pilha - ponteiro para a struct com os dados da pilha
  =========================================================*/
void mostrarPilha(TPilha const * const pilha);

/*=========================================================
    Função para preencher a pilha com elementos aleatorios de 0 a 50
     Parametros: 
        1 - pilha - ponteiro para a struct com os dados da pilha
        2 - quantidade - número de elementos a serem inseridos
  =========================================================*/
void preencherPilha(TPilha * const pilha, int quantidade);

/*=========================================================
    Função para ordenar a pilha usando o método de ordenação usando pilha
     Parametros: 
        1 - pilha - ponteiro para a struct com os dados da pilha
  =========================================================*/
  void ordenarPilha(TPilha * const pilha);

#endif