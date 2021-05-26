#include <stdio.h>
#include <stdlib.h>
#include<string.h>
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
  if(pilha_vazia(pi)){
    return 0; //não se pode remover algo vazio
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
//invertendo a lista
Pilha* inverter_pilha(Pilha *pi){
  if(pi == NULL || pilha_vazia(pi)){
    return 0; //a inversão não aconteceu
  }
  Elem *ant = NULL, *atual = (*pi), *proximo;
  while(atual->prox != NULL){
    proximo = atual->prox; //salvando o próximo elemento
    atual->prox = ant; //dizendo que o próximo é igual ao anterior, o primeiro será NULL
    ant = atual; //o anterior agora é o atual, pois na proxima repetiação do laço ele será o antecessor
    atual = proximo; //atualizando o atual
  }
  atual->prox = ant;
  *pi = atual;
  return pi;
  //uma outra maneira de resolver seria apenas criando uma outra pilha e removendo e passando os elementos para a pilha nova. Fiz desta maneira para exercitar esse raciocínio. De qualquer modo, a complexidade envolveria a mesma complexidade O(n).
};

int pilhas_iguais(Pilha *pi, Pilha* pi2){
  if(pi == NULL || pi2 == NULL){
    return -1; //as pilhas nem se quer foram criada
  }
  Elem *aux = *pi, *aux2 = *pi2;
  if(tamanho_pilha(pi) != tamanho_pilha(pi2)){
    return 0;
  } //verificando se o tamanho das pilhas são iguais para continuar

  while(aux != NULL){
    if((*aux).dados.cpf != (*aux2).dados.cpf){
      return 0; //verificando cada valor das pilhas
    }
    aux = aux->prox;
    aux2 = aux2->prox;
  }

  return 1;
};

Pilha* ordernar_pilha(Pilha *pi){
  if(pi == NULL){
    return 0;
  }
  Pessoa pessoa;
  Pilha* piAux = criar_pilha();
  Elem *aux = *pi;
  while(!pilha_vazia(pi)){
    consultar_pilha(pi, &pessoa);
    remover_pilha(pi);
    inserir_pilha(piAux, pessoa);
  }

  
  Elem *aux2 = *piAux, *anterior;
  while(!pilha_vazia(&aux2)){
    if(pilha_vazia(pi)){
      inserir_pilha(pi, (*piAux)->dados);
      remover_pilha(&aux2);
      continue;
    }

    anterior = *pi;
    aux = *pi;
    while((*aux2).dados.cpf < (aux)->dados.cpf && (aux)->prox != NULL){
      anterior = aux;
      aux = aux->prox;
    }
    if(aux2 > aux){
      (aux2)->prox = aux;
      if(anterior == aux){
        *pi = aux2;
      } else {
        if(anterior == *pi){
          (*pi)->prox = aux2;
        } else {
          anterior->prox = aux2;
        }
      }
    } else {
      aux2->prox = aux->prox;
      if(anterior == *pi){
        (*pi)->prox = aux;
      } 
      (aux)->prox = aux2;
    }
    remover_pilha(&aux2);
  }

  printf("%d", (*pi)->prox->dados.cpf);
  return pi;
};
//exibindo todos os cpfs da pilha
void mostrar(Pilha *pi){
  Elem *aux = *pi;
  printf("\nMostrando cpfs da pilha\n\n");
  while(aux != NULL){
    printf("%d\n", aux->dados.cpf);
    aux = aux->prox;
  }
}

int verificar_expressão(char expressao[]){
  Pilha *pi = criar_pilha();
  Pessoa dados;
  for(int i = 0; i<strlen(expressao); i++){
    if(expressao[i] == '('){
      inserir_pilha(pi, dados);
    } 
    if(expressao[i] == ')'){
      remover_pilha(pi);
    }
  }

  if(pilha_vazia(pi)){
    printf("Correto\n");
    return 1;
  } else {
    printf("Incorreto\n");
    return 0;
  }

};