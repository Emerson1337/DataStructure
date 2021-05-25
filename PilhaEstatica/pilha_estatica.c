#include <stdio.h>
#include <stdlib.h>
#include "pilha_estatica.h"

struct pilha {
  int qtd;
  struct pessoa dados[MAX];
};
//criando pilha
Pilha* criar_pilha(){
  Pilha *pi;
  pi = (Pilha*) malloc(sizeof(struct pilha));
  if(pi != NULL){
    pi->qtd = 0;
  }
  return pi;
};

//destruindo pilha
void destruir_pilha(Pilha *pi){
  free(pi);
};
//retornando o tamanho da pilha
int tamanho_pilha(Pilha *pi){
  if(pi == NULL){
    return -1; //pois a pilha nem se quer foi criada
  }
  return pi->qtd;
};
//verificando se a pilha se encontra cheia, 1 sim, 0 não
int pilha_cheia(Pilha *pi){
  if(pi == NULL){
    return -1; //pois a pilha nem se quer foi criada
  }

  if(pi->qtd == MAX){
    return 1;
  } else {
    return 0;
  }
};
//verificando se a pilha se encontra vazia, 1 sim, 0 não
int pilha_vazia(Pilha *pi){
  if(pi == NULL){
    return -1; //pois a pilha nem se quer foi criada
  }
  if(pi->qtd == 0){
    return 1;
  } else {
    return 0;
  }
};
//inserindo elemento na pilha
int inserir_pilha(Pilha *pi, struct pessoa dados){
  if(pi == NULL){
    return -1; //a pilha nem se quer foi criada
  }

  if(pilha_cheia(pi)){
    return 0; //falha ao inserir, pois a pilha está cheia
  }
  pi->dados[pi->qtd] = dados; //lembrando que o struct pilha possui qtd e dados
  pi->qtd++;
  return 1; //1 == sucesso!
};
//removendo elementos na pilha
int remover_pilha(Pilha *pi){
  if(pi == NULL){
    return -1; //a pilha nem se quer foi criada
  }
  if(pilha_vazia(pi)){
    return 0; //não se pode remover algo vazio
  }
  pi->qtd--;//apenas se remove 1 da quantidade, pois agora o ultimo valor se torna inacessível
  return 1;
};
//consultando o elemento mais acima da pilha
int consultar_pilha(Pilha *pi, struct pessoa *dados){
  if(pi == NULL){
    return -1; //a pilha nem se quer foi criada;
  }
  if(pilha_vazia(pi)){
    return 0; //a pilha não tem elemento para ser exibido
  }
  *dados = pi->dados[pi->qtd-1]; 
  return 1;
};

