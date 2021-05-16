#ifndef FILA_ESTATICA_H
#define FILA_ESTATICA_H

struct pessoa {
  int idade;
  char nome[30];
  int cpf;
};

typedef struct fila Fila;
typedef struct pessoa Alguem;

Fila* criar_fila();
int inserir_fila(Fila *fi, struct pessoa);
int remover_fila(Fila *fi, struct pessoa *);
int consultar_fila(Fila *fi, struct pessoa *);
void destruir_fila(Fila *fi);
int tamanho_fila(Fila *fi);
int fila_cheia(Fila *fi);
int fila_vazia(Fila *fi);
void mostrar(Fila *fi);

Fila* copiar_fila(Fila* fi);
Fila* concatenar_filas(Fila* fi, Fila* fi2);
Fila* inverter_fila(Fila* fi);




#endif