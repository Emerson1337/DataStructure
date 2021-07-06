#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

struct NO {
  int info;
  struct NO *esq;
  struct NO *dir;
};

//criando a arvore
ArvBin* criar_arvore(){
  ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
  if(raiz != NULL){
    *raiz = NULL;
  }
  return raiz;
}

//destruindo arvore
//liberacao de no
void liberar_no(struct NO* no){
  if(no == NULL){
    return;
  }
  liberar_no(no->esq);
  liberar_no(no->dir);
  free(no);
  no = NULL;
}
//liberacao do no raiz
void liberar_arvore(ArvBin* raiz){
  if(raiz == NULL){
    return;
  }
  liberar_no(*raiz);
  free(raiz);
}

//verificando se a arvore esta vazia
int arvore_vazia(ArvBin *raiz){
  if(raiz == NULL){
    return 1;
  }
  if(*raiz == NULL){
    return 1;
  }
  return 0;
}

//retornando a altura da arvore
int altura_arvore(ArvBin *raiz){
  if(raiz == NULL){
    return 0;
  }
  if(*raiz == NULL){
    return 0;
  }

  int alt_esq = altura_arvore(&((*raiz)->esq));
  int alt_dir = altura_arvore(&((*raiz)->dir));

  //verificando qual a maior altura, para assim retornar
  if(alt_esq > alt_dir){
    return (alt_esq + 1);
  } else {
    return (alt_dir + 1);
  }
}

//contando quantos nos tem na arvore
int total_no_arvore(ArvBin *raiz){
  if(raiz == NULL){
    return 0;
  }
  if(*raiz == NULL){
    return 0;
  }
  //o tanto de nos eh proporcional a cada altura de cada lado de cada no
  int alt_esq = altura_arvore(&((*raiz)->esq));
  int alt_dir = altura_arvore(&((*raiz)->dir));

  return (alt_esq + alt_dir + 1);
}

//percorrendo preordem
void preordem_arvore(ArvBin* raiz){
  if(raiz == NULL){
    return;
  }
  if(*raiz != NULL){
    printf("%d\n", (*raiz)->info);
    preordem_arvore(&((*raiz)->esq));
    preordem_arvore(&((*raiz)->dir));
  }
}

//percorrendo preordem
void emordem_arvore(ArvBin* raiz){
  if(raiz == NULL){
    return;
  }
  if(*raiz != NULL){
    emordem_arvore(&((*raiz)->esq));
    printf("%d\n", (*raiz)->info);
    emordem_arvore(&((*raiz)->dir));
  }
}

//percorrendo preordem
void posordem_arvore(ArvBin* raiz){
  if(raiz == NULL){
    return;
  }
  if(*raiz != NULL){
    posordem_arvore(&((*raiz)->esq));
    posordem_arvore(&((*raiz)->dir));
    printf("%d\n", (*raiz)->info);
  }
}

//inserindo elemento na arvore
int inserir_arvore(ArvBin* raiz, int valor){
  if(raiz == NULL){
    return 0;
  }
  struct NO* novo;
  novo = (struct NO*) malloc(sizeof(struct NO));

  if(novo == NULL){
    return 0;
  }

  novo->info = valor;
  novo->dir = NULL;
  novo->esq = NULL;

  if(*raiz == NULL){
    *raiz = novo;
  } else {
    struct NO* atual = *raiz;
    struct NO* ant = NULL;
    while(atual != NULL){
      ant = atual;
      if(valor == atual->info){
        free(novo);
        return 0;
      }
      if(valor > atual->info){
        atual = atual->dir;
      } else {
        atual = atual->esq;
      }
    }

    if(valor > ant->info){
      ant->dir = novo;
    } else {
      ant->esq = novo;
    }
  }

  return 1;
}


//removendo elementos da arvore
struct NO* remove_atual(struct NO* atual){
  struct NO *no1, *no2;
  if(atual->esq == NULL){
    no2 = atual->dir;
    free(atual);
    return no2;
  }

  no1 = atual;
  no2 = atual->esq;
  while(no2->dir != NULL){
    no1 = no2;
    no2 = no2->dir;
  }

  if(no1 != atual){
    no1->dir = no2->esq;
    no2->esq = atual->esq;
  }
  no2->dir = atual->dir;
  free(atual);

  return no2;
}

int remove_arvore(ArvBin *raiz, int valor){
  if(raiz == NULL){
    return 0;
  }
  struct NO* ant = NULL;
  struct NO* atual = *raiz;
  while(atual != NULL){
    if(valor == atual->info){
      if(atual == *raiz){
        *raiz = remove_atual(atual);
      } else {
        if(ant->dir == atual){
          ant->dir = remove_atual(atual);
        } else {
          ant->esq = remove_atual(atual);
        }
      }
      return 1;
    }
    ant = atual;
    if(valor > atual->info){
      atual = atual->dir;
    } else {
      atual = atual->esq;
    }
  }
  return 0;
};

void destruir_arvore(ArvBin *raiz){
  if(raiz == NULL){
    return;
  }
  //removando a raiz ate que nao exista mais uma na arvore.
  while(!arvore_vazia(raiz)){
    remove_arvore(raiz, (*raiz)->info);
  }
}

//consultando se um elemento se encontra na arvore
int consultar_arvore(ArvBin *raiz, int valor){
  if(raiz == NULL){
    return 0;
  }
  struct NO* atual = *raiz;
  while(atual != NULL){
    if(valor == atual->info){
      return 1;
    }
    if(valor > atual->info){
      atual = atual->dir;
    } else {
      atual = atual->esq;
    }
  }
  return 0;
}

//consultando se um elemento se encontra na arvore
int verificar_arvores(ArvBin *raiz, ArvBin *raiz2){
  
  //tratando para o caso em que os elementos comparados sao nulos e evitando
  //o erro de acesso ao atributo info ((*raiz2)->info), pois nulos sao iguais
  if(*raiz == NULL && *raiz2 == NULL){
    return 1;
  }

  //se nao caiu no if acima, precisamos verificar se algum dos elementos
  //eh nulo. Caso sim, entao ja sabemos que sao diferentes, logo, a arvore
  //nao eh igual.
  if(*raiz == NULL || *raiz2 == NULL){
    return 0;
  }

  //comparando os valores respectivos da arvore.
  if((*raiz)->info != (*raiz2)->info){
    return 0;
  };

  //verificando se a ultima funcao executada da pilha encontrou alguma
  //incosistencia, caso sim, é retornado 0, caso nao, a funcao retornara 1
  //ate que toda a pilha de execucao acabe.
  if( (!verificar_arvores(&((*raiz)->esq), &((*raiz2)->esq)))
                              ||
    (!verificar_arvores(&((*raiz)->dir), &((*raiz2)->dir)))
  ){
    return 0;
  }

  return 1;
}

//calculando o fator de balanceamento do no
int balanceamentoNO(ArvBin *raiz){
  
  //verificando se um dos elementos eh nulo, para assim evitar segmentation fault
  if(*raiz == NULL){
    return 1;
  }

  //pegando valores da esquerda e direita de um no
  struct NO *noEsq = (*raiz)->esq;
  struct NO *noDir = (*raiz)->dir;

  //calculando o fato de balanceamento de cada no 
  if((labs(altura_arvore(&noEsq) - altura_arvore(&noDir))) >= 2){
    return 0;
  } 
  //aplicando a recursividade
  if(!balanceamentoNO(&(*raiz)->esq) || !balanceamentoNO(&(*raiz)->dir)){
    return 0;
  } 

  return 1;
}
