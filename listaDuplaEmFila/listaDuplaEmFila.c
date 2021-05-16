#include <stdio.h>
#include <stdlib.h>
#include "listaDuplaEmFila.h"

struct elemento{
  struct elemento *ant;
  struct pessoa dados;
  struct elemento *prox;
};

typedef struct elemento Elem;

//Criando lista
Lista* criar_lista(){
  Lista* li = (Lista*) malloc(sizeof(Lista));
  if(li != NULL){
    *li = NULL;
  }
  return li;
}

//Excluindo lista
void destruir_lista(Lista* li){
  if(li != NULL){
    Elem* no;
    while((*li) != NULL){
      no = *li;
      *li = (*li)->prox;
      free(no);
    }
    free(li);
  }
}

//Verificando se a lista está cheia
int lista_cheia(Lista *li){
  return 0;
}

//Verificando se a lista está vazia
int lista_vazia(Lista *li){
  if(li == NULL || *li == NULL ){
    return 1;
  }
  return 0;
}

//Exibindo o tamanho da lista
int tamanho_lista(Lista *li){
  if(li == NULL){
    return 0;
  }
  Elem* no = *li;
  int count = 0;
  while(no != NULL){
    count ++;
    no = no->prox;
  };
  return count;
};
//Inserindo elementos no final da lista
int inserir_final(Lista* li, Pessoa dados){
  if(li == NULL){
    return 0; //se a lista nao existir
  }
  Elem* no = (Elem*) malloc(sizeof(Elem));
  if(no == NULL){ 
    return 0;
  }
  no->dados = dados;
  no->prox = NULL;
  if(lista_vazia(li)){
    no->ant = NULL;
    *li = no; 
    return 1;
  }
  Elem* aux = *li;
  while(aux->prox != NULL){
    aux = aux->prox;
  }
  aux->prox = no;
  no->ant = aux;
  return 1;
}
//Inserindo elementos no inicio da lista
int inserir(Lista* li, Pessoa dados){
    if(li == NULL){
      return 0; //se a lista nao existir
    }

    Elem* no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL){ 
      return 0;
    }
    no->dados = dados;

    if(lista_vazia(li)){
      no->ant = NULL;
      no->prox = NULL;
      (*li) = no;
    } else {
      inserir_final(li, dados);
    }

    return 1;
}
//Removendo elementos do inicio da lista
int remover_inicio(Lista* li){
  if(li == NULL){
    return 0;
  }
  if(lista_vazia(li)){
    return 0;
  }
  Elem* no = (*li);
  *li = no->prox; 
  if((*li) != NULL){
    no->prox->ant = NULL;  
  }
  
  free(no);
  return 1;
}
//Removendo elementos do inicio da lista
int remover(Lista* li){
  if(li == NULL){
    return 0;
  }
  if(lista_vazia(li)){
    return 0;
  }

  remover_inicio(li);
  return 1;
}

//Buscando elemento na lista por posição
int consultar(Lista* li, struct pessoa *dados){
  if(li == NULL || lista_vazia(li)){
    return 0;
  }
  *dados = (*li)->dados;
  return 1;
};
