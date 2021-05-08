#include <stdio.h>
#include <stdio.h>
#include "listaEstatica.h"

int main(void) {
  Lista *li;
  Pessoa human;
  char nomeVar[30] = "Emerson";

  human.nome[29] = nomeVar[29];
  human.idade = 19;
  human.cpf = 12345678;

  li = criar_lista();
  int x = inserir_inicio(li, human);
  printf("Inserção no inicio da lista: %d\n", x);
  int y = inserir_final(li, human);
  printf("Inserção no fim da lista: %d\n", y);
  int z = inserir_meio(li, human);
  printf("Inserção no meio da lista: %d\n", z);
  printf("\n\n");

  int t = remover_inicio(li);
  printf("Remoção no inicio da lista: %d\n", t);
  int w = remover_final(li);
  printf("Remoção no fim da lista: %d\n", w);
  int k = remover_meio(li, human.cpf);
  printf("Remoção no meio da lista: %d\n", k);
  printf("\n\n");

  int j = tamanho_lista(li);
  printf("tamanho da lista: %d\n", j);
  int n = lista_cheia(li);
  printf("Lista cheia: %d\n", n);
  int a = lista_vazia(li);
  printf("Lista vazia: %d\n", a);
  int h = consultar_lista(li, human);
  printf("Consultar na lista: %d\n", h);

  destruir_lista(li);
  return 0;
}