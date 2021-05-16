#include <stdio.h>
#include <stdlib.h>
#include "filaEstatica.h"

int main(void) {
  Fila *fi;
  Alguem human;
  Alguem human2;
  Alguem alguem;

  char nomeVar[30] = "Emerson";
  human.nome[29] = nomeVar[29];
  human.idade = 19;
  human.cpf = 99999999;

  char nomeVar2[30] = "Ana Luiza";
  human2.nome[29] = nomeVar[29];
  human2.idade = 25;
  human2.cpf = 12345678;

  fi = criar_fila();

  int x = inserir_fila(fi, human);
  printf("Inserção na fila: %d\n", x);
  int z = inserir_fila(fi, human2);
  printf("Inserção na fila: %d\n", z);
  int y = consultar_fila(fi, &alguem);
  printf("Consultando o inicio da lista: %d\n", y);
  printf("CPF da primeira pessoa da fila: %d\n", alguem.cpf);
  printf("Tamanho da fila antes da remoção: %d\n", tamanho_fila(fi));
  int i = remover_fila(fi, &alguem);
  printf("Operação de remoção da fila: %d\n", i);
  printf("CPF de quem foi removido: %d\n", alguem.cpf);
  printf("Tamanho da fila depois da remoção: %d\n", tamanho_fila(fi));
  int cheia = fila_cheia(fi);
  printf("Lista cheia: %d\n", cheia);
  int vazia = fila_cheia(fi);
  printf("Lista vazia: %d\n", vazia);

  destruir_fila(fi);
  return 0;
}