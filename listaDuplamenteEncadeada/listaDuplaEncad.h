#ifndef LISTA_DUPLA_ENCAD_H
#define LISTA_DUPLA_ENCAD_H

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
int inserir_inicio(Lista* li, Pessoa dados);
int inserir_final(Lista* li, Pessoa dados);
int inserir_meio(Lista* li, Pessoa dados);
int remover_inicio(Lista* li);
int remover_fim(Lista* li);
int remover_meio(Lista* li, int);
int buscar_lista_valor(Lista* li, int, Pessoa *dados);
int buscar_lista_pos(Lista* li, int, Pessoa *dados);
int inverter_lista(Lista* li, Lista *l2);
int remover_repetidos(Lista* li, Lista *l2);
int verificar_igualdade(Lista* li, Lista l2);




#endif