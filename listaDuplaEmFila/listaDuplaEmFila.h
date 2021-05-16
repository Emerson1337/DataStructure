#ifndef LISTA_DUPLA_EM_FILA_H
#define LISTA_DUPLA_EM_FILA_H

struct pessoa {
  int idade;
  char nome[30];
  int cpf;
};

typedef struct pessoa Pessoa;
typedef struct elemento* Lista;

Lista* criar_lista();
void destruir_lista(Lista* li);
int lista_cheia(Lista *li);
int lista_vazia(Lista *li);
int tamanho_lista(Lista *li);
int inserir(Lista* li, Pessoa dados);
int remover(Lista* li);
int consultar(Lista* li, Pessoa *dados);




#endif