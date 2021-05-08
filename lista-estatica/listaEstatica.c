#include <stdio.h>
#include <stdlib.h>
#include "listaEstatica.h"

struct lista {
  int qtd;
  struct pessoa dados[MAX];
};
//criando lista
Lista* criar_lista(){
  Lista *li;
  li = (Lista*) malloc(sizeof(struct lista));
  if(li != NULL){
    li->qtd = 0;
  }
  return li;
};
//destruindo lista
void destruir_lista(Lista* li){
  free(li);
};
//retornando o tamanho da lista
int tamanho_lista(Lista* li){
  if(li == NULL){
    return -1;
  } else {
    return li->qtd;
  }
}
//retornando se lista está cheia ou vazia
int lista_cheia(Lista* li){
  if(li == NULL){
   return -1;
  }
  if(li->qtd == MAX) {
    return 1;
  } else {
    return 0;
  }
}
//retornando se lista está cheia ou vazia
int lista_vazia(Lista* li){
  if(li == NULL){
    return -1;
  }
  if(li->qtd == 0) {
    return 1;
  } else {
    return 0;
  }
}
//inserindo elemento no inicio
int inserir_inicio(Lista* li, struct pessoa dados){
  if(li == NULL){
    return 0;
  } else if(lista_cheia(li)){
    return 0;
  }
  if(lista_vazia(li)){
    li->dados[0] = dados;
    li->qtd++;
    return 1;
  }
  int aux = li->qtd;
  while(aux != 0){
    li->dados[aux] = li->dados[aux-1];
    aux--;
  }
  li->dados[0] = dados;
  li->qtd++;
  return 1;
}
//inserindo elemento no fim
int inserir_final(Lista* li, struct pessoa dados){
  if(li == NULL){
    return 0;
  } else if(lista_cheia(li)){
    return 0;
  }
  li->dados[li->qtd] = dados;
  li->qtd++;
  return 1;
}
//inserindo no meio de forma ordenada
int inserir_meio(Lista* li, struct pessoa dados){
  if(li == NULL){
    return 0;
  } else if(lista_cheia(li)){
    return 0;
  }
  int i = 0;
  while(i<li->qtd && li->dados[i].cpf < dados.cpf){
    i++;
  }
  for(int k = li->qtd-1; k>=i; k--){
    li->dados[k+1] = li->dados[k];
  }
  li->dados[i] = dados;
  li->qtd++;
  return 1;
}
//removendo elemento do inicio
int remover_inicio(Lista* li){
  if(li == NULL){
    return 0;
  } else if(lista_vazia(li)){
    return 0;
  }
  int i = li->qtd;
  for(int k = 0; k<i-1; k++){
    li->dados[k] = li->dados[k+1];
  }
  li->qtd--;
  return 1;
}
//removendo elemento do inicio
int remover_final(Lista* li){
  if(li == NULL){
    return 0;
  } else if(lista_vazia(li)){
    return 0;
  }
  li->qtd--;
  return 1;
}
//removendo elemento do meio da lista
int remover_meio(Lista* li, int cpf){
  if(li == NULL){
    return 0;
  } else if(lista_vazia(li)){
    return 0;
  }
  int i = 0;
  while(i<li->qtd && li->dados[i].cpf != cpf){
    i++;
  }
  if(i == li->qtd){
    return 0; //404 not found
  }

  for(int k = i; k < li->qtd-1; k++){
    li->dados[k] = li->dados[k+1];
  }
  li->qtd--;
  return 1;
}
//Consultando na lista por valor
int consultar_lista_valor(Lista* li, int cpf, struct pessoa *dados){
  if(li == NULL){
    return 0;
  } else if(lista_vazia(li)){
    return 0;
  }
  for(int i = 0; i < li->qtd; i++){
    if(li->dados[i].cpf == cpf){
      *dados = li->dados[i];
      return 1;
    }
  }
  return 0;
};
//Consultando na lista por posição
int consultar_lista_pos(Lista* li, int pos, struct pessoa *dados){
  if(li == NULL || pos > li->qtd || pos <= 0 ){
    return 0;
  }
  if(lista_vazia(li)){
    return 0;
  }
  *dados = li->dados[pos-1];
  return 1;
};