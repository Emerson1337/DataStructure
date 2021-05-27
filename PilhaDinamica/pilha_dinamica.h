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
void mostrar(Pilha *pi);
int verificar_expressão(char []);
Pilha* ordernar_pilha(int numbers[], int tamanho);
void mostrar_por_idade(Pilha *pi);

#endif