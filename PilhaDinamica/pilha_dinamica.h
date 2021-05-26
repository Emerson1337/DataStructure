#ifndef PILHA_DINAMICA_H
#define PILHA_DINAMICA_H

struct pessoa {
  int cpf;
  int nome[30];
  int idade;
};

typedef struct elemento *Pilha;
typedef struct pessoa Pessoa;

Pilha* criar_pilha();
int tamanho_pilha(Pilha *pi);
int destruir_pilha(Pilha *pi);
int inserir_pilha(Pilha *pi, struct pessoa dados);
int remover_pilha(Pilha *pi);
int consultar_pilha(Pilha *pi, struct pessoa *dados);
Pilha* inverter_pilha(Pilha *pi);
int pilhas_iguais(Pilha *pi, Pilha *pi2);
Pilha* ordernar_pilha(Pilha *pi);
void mostrar(Pilha *pi);
int verificar_expressão(char []);

#endif