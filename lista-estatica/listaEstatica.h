#ifndef LISTA_ESTATICA_H
#define LISTA_ESTATICA_H

#define MAX 100
struct pessoa {
  int idade;
  char nome[30];
  int cpf;
};

typedef struct pessoa Pessoa;
typedef struct lista Lista;


Lista* criar_lista();
void destruir_lista(Lista *);
int tamanho_lista(Lista *);
int lista_cheia(Lista* li);
int lista_vazia(Lista* li);
int inserir_inicio(Lista* li, struct pessoa dados);
int inserir_final(Lista* li, struct pessoa dados);
int inserir_meio(Lista* li, struct pessoa dados);
int remover_inicio(Lista* li);
int remover_meio(Lista* li, int);
int remover_final(Lista* li);
int consultar_lista_valor(Lista* li, int, struct pessoa *dados);
int consultar_lista_pos(Lista* li, int, struct pessoa *dados);
Lista* inverter_lista(Lista* li);
Lista* remover_repetidos(Lista* li);




#endif