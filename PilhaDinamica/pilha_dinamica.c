#include <stdio.h>
#include <stdlib.h>
#include "pilha_dinamica.h"

struct elemento {
  struct pessoa dados;
  struct elemento *prox;
};

typedef struct elemento Elem;
//criando a pilha
Pilha* criar_pilha(){
  Pilha *pi = (Pilha*) malloc(sizeof(Pilha));
  if(pi != NULL){ // se a memória foi alocada e não está como NULL, então é setado
    *pi = NULL;
  }
  return pi;
};
//destruindo a pilha
int destruir_pilha(Pilha *pi){
  if(pi != NULL){
    return 0; //a pilha não está definida
  }
  Elem *aux;
  while((*pi) != NULL){
    aux = *pi; //pegando o elemento a ser destruido
    (*pi) = (*pi)->prox; //pegando o próximo elemento encadeado
    free(aux); //excluindo o elemento atual
  }
  free(pi); //finalizando a destruição da pilha
  return 1;  
};  
//verificando o tamanho da pilha
int tamanho_pilha(Pilha *pi){
  if(pi == NULL){
    return -1; //a pilha nem se quer foi criada
  }
  int tamanho = 0;
  Elem *aux = *pi;
  while(aux != NULL){
    aux = aux->prox;
    tamanho++;
  }
  return tamanho;
};
//verificando se a pilha está vazia
int pilha_vazia(Pilha *pi){
  if(pi == NULL){
    return -1; //a pilha nem se quer foi criada
  }
  if(*pi == NULL){
    return 1;
  } else {
    return 0;
  }
};
//verificando se a pilha está cheia
int pilha_cheia(Pilha *pi){
  return 0; //pois a alocação é dinâmica, ela estará cheia quando toda a memória do computador estiver ocupada
};
//inserindo elementos na pilha
int inserir_pilha(Pilha *pi, struct pessoa dados){
  if(pi == NULL){
    return -1; //a pilha nem se quer foi criada
  }
  Elem* aux = (Elem*) malloc(sizeof(Elem));
  if(aux == NULL){
    return 0; //o elemento não foi criado
  }
  aux->dados = dados;
  aux->prox = *pi;
  *pi = aux;
  return 1;
};
//removendo elementos na pilha
int remover_pilha(Pilha *pi){
  if(pi == NULL){
    return -1; //a pilha nem se quer foi criada
  }
  Elem* aux = *pi;
  *pi = (*pi)->prox;
  free(aux);
  return 1;
};
//consultando elemento da pilha
int consultar_pilha(Pilha *pi, struct pessoa *dados){
  if(pi == NULL){
    return -1; //a pilha nem se quer foi criada
  }
  if(pilha_vazia(pi)){
    return 0; //a pilha não possui elementos;
  }
  *dados = (*pi)->dados;
  return 1;
};