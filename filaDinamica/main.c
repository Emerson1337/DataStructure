#include <stdio.h>
#include <stdlib.h>
#include "filaDinamica.h"

int main(void) {
  Fila *fi;
  Fila *filaTeste;
  Fila *resultado;
  Alguem human;
  Alguem human2;
  Alguem human3;
  Alguem alguem;

  char nomeVar[30] = "Emerson";
  human.nome[29] = nomeVar[29];
  human.idade = 19;
  human.cpf = 99999999;

  char nomeVar2[30] = "Ana Luiza";
  human2.nome[29] = nomeVar[29];
  human2.idade = 25;
  human2.cpf = 12345678;

  char nomeVar3[30] = "Anaaa Luiza";
  human3.nome[29] = nomeVar[29];
  human3.idade = 25;
  human3.cpf = 454544542;

  fi = criar_fila();

  int x = inserir_fila(fi, human);
  printf("Inserção na fila: %d\n", x);
  int z = inserir_fila(fi, human2);
  printf("Inserção na fila: %d\n", z);
  int zf = inserir_fila(fi, human3);


  consultar_fila(fi, &alguem);
  printf("CPF da primeira pessoa da lista: %d\n", alguem.cpf);
  printf("Tamanho da fila depois da remoção: %d\n", 
  tamanho_fila(fi));

  resultado = inverter_fila(fi);
  printf("\n*FILA INVERTIDA*\n\n");
  mostrar(resultado);
  consultar_fila(resultado, &alguem);
  printf("CPF da primeira pessoa da lista: %d\n", alguem.cpf);
  printf("Tamanho da fila depois da inversão: %d\n\n", 
  tamanho_fila(resultado));




  // filaTeste = copiar_fila(fi);
  // printf("Lista copiada\n");

  // printf("Tamanho da fila antes da remoção: %d\n", tamanho_fila(fi));
  // int i = remover_fila(fi, &alguem);
  // printf("Operação de remoção da fila: %d\n", i);
  // printf("CPF de quem foi removido: %d\n", alguem.cpf);

  // printf("Tamanho da fila copiada\nsem ter elementos removidos: %d\n", tamanho_fila(filaTeste));
  // int y = consultar_fila(filaTeste, &alguem);
  // printf("Consultando o inicio da lista: %d\n", y);
  // printf("CPF da primeira pessoa da fila: %d\n\n", alguem.cpf);

  // resultado = concatenar_filas(fi, filaTeste);
  // printf("Tamanho da fila concatenada: %d\n", tamanho_fila(resultado));
  // consultar_fila(fi, &alguem);
  // printf("CPF da primeira pessoa da lista: %d\n", alguem.cpf);
  
  // int cheia = fila_cheia(fi);
  // printf("Lista cheia: %d\n", cheia);
  // int vazia = fila_cheia(fi);
  // printf("Lista vazia: %d\n", vazia);

  return 0;
}