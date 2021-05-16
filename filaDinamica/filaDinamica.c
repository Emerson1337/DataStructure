#include <stdio.h>
#include <stdlib.h>
#include "filaDinamica.h"

struct fila {
  struct elemento *inicio;
  struct elemento *fim;
};

struct elemento {
  struct pessoa dados;
  struct elemento *prox;
};

typedef struct elemento Elem;

//criando fila.
Fila* criar_fila(){
  Fila *fi = (Fila*) malloc(sizeof(struct fila));
  if(fi == NULL) {
    return 0; //verificando se foi possível alocar espaço na memória
  }
  fi->inicio = NULL;
  fi->fim = NULL;

  return fi;
};
//inserindo elemento na fila
int inserir_fila(Fila *fi, struct pessoa Pessoa){
  if(fi == NULL) {
    return -1;//-1 pois a fila nem se quer existe
  }
  Elem *aux = (Elem*) malloc(sizeof(struct elemento));
  if(aux == NULL){
    return 0;
  }
  aux->dados = Pessoa;
  aux->prox = NULL;
  if(fila_vazia(fi)){
    fi->inicio = aux; //se for vazio, o fim = inicio
  } else {
    fi->fim->prox = aux; //se nao, o prox final será o aux
  }
  fi->fim = aux;
  return 1;
};
//removendo elemento da fila
int remover_fila(Fila *fi, struct pessoa *Pessoa){
  if(fi == NULL){
    return -1; //-1 pois a fila nem se quer existe
  }
  if(fila_vazia(fi)){
    return 0;
  }
  Elem *aux = fi->inicio; //sempre se remove o inicio
  *Pessoa = fi->inicio->dados; //informando ao usuário quem foi removido
  if(fi->inicio->prox == NULL){ //só temos 1 elemento
    fi->fim = NULL;
  }
  fi->inicio = fi->inicio->prox;
  free(aux);
  return 1;
};
int consultar_fila(Fila *fi, struct pessoa *Pessoa){
  if(fi == NULL){
    return -1; //-1 pois a fila nem se quer existe
  }
  if(fila_vazia(fi)){
    return 0;
  }

  *Pessoa = fi->inicio->dados;
  return 1;
};
//destruindo fila
void destruir_fila(Fila *fi){
  if(fi != NULL){
    Elem* aux;
    while(fi->inicio != NULL){
      aux = fi->inicio;
      fi->inicio = fi->inicio->prox;
      free(aux);
    }
    free(fi);
  }
}
//tamanho da fila
int tamanho_fila(Fila *fi){
  if(fi == NULL){
    return -1; //-1 pois a fila nem se quer existe
  }
  Elem *aux = fi->inicio;
  int qtd = 0;
  while(aux != NULL){
    qtd++;
    aux = aux->prox;
  }
  return qtd;
};
//verificando se a fila está cheia
int fila_cheia(Fila *fi){
  if(fi == NULL){
    return -1; //-1 pois a fila nem se quer existe
  }
  return 0;
};
//verificando se a fila está cheia
int fila_vazia(Fila *fi){
  if(fi == NULL){
    return 1; //-1 pois a fila nem se quer existe
  }
  if(fi->inicio == NULL){
    return 1;
  }
  return 0;
};

//fazendo a cópia das filas para outro ponteiro
Fila* copiar_fila(Fila* fi){
  if(fi == NULL){
    return 0;
  }
  if(fila_vazia(fi)){
    return 0;
  }

  Fila* fi2 = criar_fila();
  Elem* aux = fi->inicio;
  while(aux != NULL){
    inserir_fila(fi2, aux->dados);
    aux = aux->prox;
  }
  return fi2;
};

//Concatenando filas
Fila* concatenar_filas(Fila* fi, Fila* fi2){
  if(fi == NULL || fi2 == NULL){
    return 0;
  }
  fi->fim->prox = fi2->inicio; //dizendo que o prox elemento do último da primeira lista é igual ao primeiro elemento da segunda lista.
  fi->fim = fi2->fim; //atribuindo que o fim da lista 1, agora é o fim da lista 2
  destruir_fila(fi2);
  return fi;
};

//invertendo fila
Fila* inverter_fila(Fila* fi){
  if(fi == NULL || fila_vazia(fi)){
    return 0;
  }
  Elem *ant = NULL, *atual = fi->inicio, *proximo, *primeiroElemento = fi->inicio;
  while(atual != NULL){
    proximo = atual->prox; //apenas salvando o prox do atual.
    atual->prox = ant; //o próximo deste elemento será o anterior, se for o primeiro elemento da lista, será NULL.
    ant = atual; //apenas armazenando o atual para apontarmos no próximo loop
    atual = proximo; //percorrendo a fila
  }
  fi->fim = primeiroElemento; //definindo que o fim da lista agora é o antigo primeiro.
  fi->inicio = ant; //reconfigurando o inicio da lista
  return fi;
};
void mostrar(Fila *fi){
  Elem* no = fi->inicio;
  while(no != NULL){
    printf("%d\n", no->dados.cpf);
    no = no->prox;
  }
};