#ifndef PILHA_ESTATICA_H
#define PILHA_ESTATICA_H

#define MAX 100

struct pessoa {
  int idade;
  char nome[30];
  int cpf;
};

typedef struct pilha Pilha;
typedef struct pessoa Pessoa;


Pilha* criar_pilha();
void destruir_pilha(Pilha *pi);
int tamanho_pilha(Pilha *pi);
int inserir_pilha(Pilha *pi, struct pessoa dados);
int remover_pilha(Pilha *pi);
int consultar_pilha(Pilha *pi, struct pessoa *dados);

#endif