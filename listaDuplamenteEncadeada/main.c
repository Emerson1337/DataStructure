#include <stdio.h>
#include <stdio.h>
#include "listaDuplaEncad.h"

int main(void) {
  Lista *li;
  Pessoa alguem;
  Pessoa human;

  char nomeVar[30] = "Emerson";
  human.nome[29] = nomeVar[29];
  human.idade = 19;
  human.cpf = 38758756;

  li = criar_lista();
  int x = inserir_inicio(li, human);
  printf("Inserção no inicio da lista: %d\n", x);
  int u = inserir_inicio(li, human); //inserção de dois elementos
  printf("Inserção no inicio da lista: %d\n", u);
  int y = inserir_final(li, human);
  printf("Inserção no fim da lista: %d\n", y);
  int z = inserir_meio(li, human);
  printf("Inserção no meio da lista: %d\n", z);
  printf("\n\n");

  int t = remover_inicio(li);
  printf("Remoção no inicio da lista: %d\n", t);
  int w = remover_fim(li);
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
  int h = buscar_lista_valor(li, human.cpf, &alguem);
  printf("Consultar na lista valor: %d\n", h);
  printf("%d\n", alguem.cpf);
  int p = buscar_lista_pos(li, 1, &alguem);
  printf("Consultar na lista posição: %d\n", p);
  printf("%d\n", alguem.cpf);


  destruir_lista(li);
  return 0;
}