#include <stdio.h>
#include <stdlib.h>
#include "listaDuplaEncad.h"

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

//Inserindo elementos no inicio da lista
int inserir_inicio(Lista* li, Pessoa dados){
    if(li == NULL){
      return 0; //se a lista nao existir
    }

    Elem* no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL){ 
      return 0;
    }

    no->ant = NULL;
    no->dados = dados;
    no->prox = (*li);
    if((*li) != NULL){
      (*li)->ant = no; //apontando o primeiro elemento
    }                  //depois do primeiro, depois  
    *li = no;          //mudando o point do 1º elem.
    return 1;
}

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

//Inserindo elementos no meio da lista de forma ordenada
int inserir_meio(Lista* li, Pessoa dados){
  if(li == NULL){
    return 0;
  }
  Elem* no = (Elem*) malloc(sizeof(Elem));
  if(no == NULL){
    return 0;
  }
  if(lista_vazia(li)){ //se for vazia
    no->prox = NULL;
    no->dados = dados;
    no->ant = NULL;
    *li = no;
    return 1;
  } else {
    Elem *ant, *atual = *li;
    no->dados = dados;
    while(atual != NULL && atual->dados.cpf < dados.cpf){
      ant = atual;
      atual = atual->prox;
    }
    if(atual == *li){
      no->ant = NULL;
      no->prox = (*li);
      (*li)->ant = no;
      *li = no;
    } else {
      no->ant = ant;
      no->prox = atual;
      ant->prox = no;
      if(atual != NULL){
        atual->ant = no;
      }
    }
    return 1;
  }
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

//Removendo elementos do fim da lista
int remover_fim(Lista* li){
  if(li == NULL){
    return 0;
  }
  if(lista_vazia(li)){
    return 0;
  }
  Elem* no = *li;
  while(no->prox != NULL){
    no = no->prox;
  }

  if(no->ant == NULL){
    *li = NULL; //só um elemento existe, logo, removemos ele
  } else {
    no->ant->prox = NULL; //dizendo que o elemento anterior ao ultimo, agora é o ultimo.
  }

  free(no);
  return 1;
}

//Removendo elementos do meio da lista de forma ordenada
int remover_meio(Lista* li, int cpf){
  if(li == NULL){
    return 0;
  }
  if(lista_vazia(li)){
    return 0;
  }
  Elem* no = *li;
  while(no != NULL && no->dados.cpf != cpf){
    no = no->prox;
  }
  if(no == NULL){
    return 0; //not found
  }
  if(no->ant == NULL){
    *li = no->prox;
    (*li)->ant = NULL;
  } else {
    no->ant->prox = no->prox;
  }
  if(no->prox == NULL){
    no->ant->prox = NULL;
  } else {
    no->prox->ant = no->ant;
  }

  free(no);
  return 1;
}

//Buscando elemento na lista por valor
int buscar_lista_valor(Lista* li, int cpf, struct pessoa *dados){
  if(li == NULL){
    return 0;
  }
  if(lista_vazia(li)){
    return 0;
  }
  Elem* no = *li;
  while(no != NULL && no->dados.cpf != cpf){
    no = no->prox;
  }
  if(no == NULL){
    return 0;
  } 
  *dados = no->dados;
  return 1;
}

//Buscando elemento na lista por posição
int buscar_lista_pos(Lista* li, int pos, struct pessoa *dados){
  if(li == NULL || pos <= 0){
    return 0;
  }
  if(lista_vazia(li)){
    return 0;
  }
  Elem* no = *li;
  int i = 1;

  while(no != NULL && i < pos){
    no = no->prox;
    i++;
  }

  if(no == NULL){
    return 0;
  }

  *dados = no->dados;
  return 1;
}

int inverter_lista(Lista* li, Lista *l2){
  if(li == NULL){
    return 0;
  }
  if(lista_vazia(li)){
    return 0;
  }
  Lista* l2cp;
  l2cp = criar_lista();
  Elem* atual = *li;
  while(atual->prox != NULL){
    inserir_inicio(l2cp , (atual)->dados);
    atual = atual->prox;
  }
  inserir_inicio(l2cp , (atual)->dados);
  *l2 = *l2cp;
  free(l2cp);
  return 1;
};

int remover_repetidos(Lista* li, Lista *l2){
  if(li == NULL){
    return 0;
  }
  if(lista_vazia(li)){
    return 0;
  }
  Lista* l2cp;
  Pessoa tem;
  l2cp = criar_lista();
  Elem* atual = (*li);
  while(atual->prox != NULL){
    if(!buscar_lista_valor(l2cp, atual->dados.cpf, &tem)){
      inserir_final(l2cp, atual->dados); //verificando se o elemento existe antes de inserir na nova lista.
    }
    atual = atual->prox;
  }
  //verificando se o último valor está na lista para inseri-lo na lista. Caso já esteja, não é inserido.
  if(!buscar_lista_valor(l2cp, atual->dados.cpf, &tem)){
      inserir_final(l2cp, atual->dados);
  }
  *l2 = *l2cp;
  return 1;
};

//verificando se as listas são iguais
int verificar_igualdade(Lista* li, Lista l2){
if(li == NULL){
    return 0;
  };
  if(l2 == NULL){
    return 0;
  };
  Elem* no = *li, *aux = l2; //pegando as duas listas
  if(tamanho_lista(li) != tamanho_lista(&l2)){ //verificando se são do mesmo tamanho, se nao, já sabemos que são diferentes.
    return 0;
  }
  while(no->prox != NULL){ //percorrendo toda a lista até o último elemento
    if(no->dados.cpf != aux->dados.cpf){
      return 0;
    }
    no = no->prox;
    aux = aux->prox;
  }
  //fazendo a ultima verificação para o ultimo elemento.
  if(no->dados.cpf != aux->dados.cpf){
      return 0;
  }
  return 1;
};
