#include <stdio.h>
#include <stdlib.h>
#include "listaEncadCircular.h"

struct elemento{
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
  if(!lista_vazia(li)){
    Elem *aux, *no = *li;
    while((*li) != no->prox){
      aux = no;
      no = no->prox;
      free(aux);
    }
    free(no);
    free(li);
  }
}

//Verificando se a lista está cheia
int lista_cheia(Lista *li){
  return 0;
}

//Verificando se a lista está vazia
int lista_vazia(Lista *li){
  if(li == NULL || (*li) == NULL ){
    return 1;
  }
  return 0;
}

//Exibindo o tamanho da lista
int tamanho_lista(Lista *li){
  if(li == NULL){
    return 0;
  }
  if(lista_vazia(li)){
    return 0;
  }
  Elem* no = *li;
  int count = 0;
  do{
    count++;
    no = no->prox;
  } while(no != (*li));

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
    no->dados = dados;
    if(lista_vazia(li)){
      *li = no;
      no->prox = no;
    } else {
      no->prox = *li;
      Elem* aux = *li;
      while(aux->prox != (*li)){
        aux = aux->prox;
      }
      aux->prox = no;
      (*li) = no;
    }
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
  if(lista_vazia(li)){
     *li = no;
      no->prox = no;
  } else {
      no->prox = *li;
      Elem* aux = *li;
      while(aux->prox != (*li)){
        aux = aux->prox;
      }
      aux->prox = no;
  }
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
  no->dados = dados;
  if(lista_vazia(li)){ //se for vazia
    no->prox = no;
    *li = no;
  } else {
    //verificando se será inserido no começo
    if((*li)->dados.cpf > dados.cpf){
      Elem* aux = *li;
      while(aux->prox != (*li)){
        aux = aux->prox;
      }
      aux->prox = no;
      no->prox = (*li);
      *li = no;
      return 1;
    }
    Elem *ant = *li, *atual = (*li)->prox;
    while(atual != (*li) && atual->dados.cpf < dados.cpf){
      ant = atual;
      atual = atual->prox;
    }
    no->prox = atual;
    ant->prox = no;
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
  if((*li)->prox == *li){ //verificando se temos apenas 1 elemento.
    free(*li);
    *li = NULL;
    return 1;
  }
  Elem *no = *li, *atual = *li;
  while(atual->prox != (*li)){
    atual = atual->prox;
  }
  atual->prox = no->prox;
  *li = no->prox;
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
  if((*li)->prox == *li){ //verificando se temos apenas 1 elemento.
    free(*li);
    *li = NULL;
    return 1;
  }
  Elem* no = *li, *ant = *li;
  while(no->prox != (*li)){
    ant = no;
    no = no->prox;
  }
  ant->prox = *li;
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
  //verificando se será removido o inicio
  if(no->dados.cpf == cpf){
    if((*li)->prox == *li){ //verificando se temos apenas 1 elemento.
      free(no);
      *li = NULL;
      return 1;
    }
    Elem* aux = *li;
    while(aux->prox != (*li)){
      aux = aux->prox;
    }
    aux->prox = (*li)->prox;
    *li = (*li)->prox;
    free(no);
    return 1;
  }
  Elem* ant;
  no = no->prox;
  while(no != (*li) && no->dados.cpf != cpf){
    ant = no;
    no = no->prox;
  }
  if(no == *li){
    return 0; //not found
  }
  ant->prox = no->prox;
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
  while(no->prox != (*li) && no->dados.cpf != cpf){
    no = no->prox;
  }
  if(no->dados.cpf != cpf){
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

  while(no->prox != (*li) && i < pos){
    no = no->prox;
    i++;
  }

  if(i != pos){
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
  while(atual->prox != *li){
    inserir_inicio(l2cp , (atual)->dados);
    atual = atual->prox;
  }
  inserir_inicio(l2cp , (atual)->dados); //INSERINDO O ÚLTIMO
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
  Pessoa tem; //Variavel apenas para chamar a função de consulta
  l2cp = criar_lista();
  Elem* atual = (*li);
  while(atual->prox != *li){
    if(!buscar_lista_valor(l2cp, atual->dados.cpf, &tem)){
      inserir_final(l2cp, atual->dados); //verificando se o elemento existe antes de inserir na nova lista.
    }
    atual = atual->prox;
  }
  //verificando se o último valor é igual ao primeiro para inserir o último elemento na lista. Caso seja, não é inserido.
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
  while(no->prox != *li){ //percorrendo toda a lista até o último elemento
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