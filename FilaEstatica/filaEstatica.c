#include <stdio.h>
#include <stdlib.h>
#include "filaEstatica.h"

struct fila {
  int inicio, fim, qtd;
  struct pessoa dados[MAX];
};

//criando a fila.
Fila* criar_fila(){
  Fila *fi = (Fila*) malloc(sizeof(struct fila));
  if(fi != NULL){
    fi->inicio = 0;
    fi->fim = 0;
    fi->qtd = 0;
  }
  return fi;
};
//inserindo elemento na fila
int inserir_fila(Fila *fi, struct pessoa Pessoa){
  if(fi == NULL){
    return -1; //-1 pois a fila nem se quer existe
  } else if(fila_cheia(fi)){
    return 0; //operação de inseração não funcionou
  }
  fi->dados[fi->fim] = Pessoa;
  fi->fim = (fi->fim+1) % MAX; //deixando a fila redundante
  fi->qtd++;
  return 1; //Operação de inseração concluida
};
//inserindo elemento na fila
int remover_fila(Fila *fi, struct pessoa *Pessoa){
  if(fi == NULL){
    return -1; //-1 pois a fila nem se quer existe
  } else if(fila_vazia(fi)){
    return 0; //operação de inseração não funcionou
  }
  *Pessoa = fi->dados[fi->inicio];
  fi->inicio = (fi->inicio+1) % MAX;//deixando a fila redundante
  fi->qtd--;
  return 1; //Operação de inseração concluida
};
//consultando primeiro elemento da fila
int consultar_fila(Fila *fi, struct pessoa *Pessoa){
  if(fi == NULL){
    return -1; //-1 pois a fila nem se quer existe
  } else if(fila_vazia(fi)){
    return 0; //operação de consulta não foi realizada
  }
  *Pessoa = fi->dados[fi->inicio];
  return 1;
};
//excluindo a fila
void destruir_fila(Fila *fi){
  free(fi);
};
//retornando o tamanho da fila passada no parâmetro
int tamanho_fila(Fila *fi){
  if(fi == NULL){
    return -1; //-1 pois a fila nem se quer existe.
  }
  return fi->qtd;
};
//verificando se a fila está cheia
int fila_cheia(Fila *fi){
  if(fi == NULL){
    return -1; //-1 pois a fila nem se quer existe
  }
  if(fi->qtd == MAX){
    return 1; //Se entrar na condição, a fila está cheia
  }
  return 0;
};
//verificando se a fila está vazia
int fila_vazia(Fila *fi){
  if(fi == NULL){
    return -1; //-1 pois a fila nem se quer existe
  }
  if(fi->qtd == 0){
    return 1;
  }
  return 0;
};