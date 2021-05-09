#include <stdio.h>
#include <stdio.h>
#include "listaEncadCircular.h"

int main(void) {
  Lista *li;
  Lista l2;
  Pessoa alguem;
  Pessoa human;
  Pessoa human2;
  Pessoa human3;
  Pessoa human4;



  char nomeVar[30] = "Emerson";
  human.nome[29] = nomeVar[29];
  human.idade = 19;
  human.cpf = 99999999;

  char teste[30] = "Ana Luiza";
  human2.nome[29] = nomeVar[29];
  human2.idade = 19;
  human2.cpf = 38758756;

  char teste2[30] = "Lula";
  human3.nome[29] = nomeVar[29];
  human3.idade = 19;
  human3.cpf = 99999999;
  char teste3[30] = "Lula";
  human4.nome[29] = nomeVar[29];
  human4.idade = 19;
  human4.cpf = 99999999;

  li = criar_lista();
  inserir_inicio(li, human);
  inserir_final(li, human2);
  inserir_final(li, human3);
  inserir_final(li, human4);
  
  //UTILIZADOS PARA TESTAR REMOÇÃO DE REPETIDOS

  //olhando os elementos antes da remoção lista Li
  printf("Mostrando li:\n");
  buscar_lista_pos(li, 1, &alguem);
  printf("Quem é o primeiro elemento: %d\n", alguem.cpf);
  buscar_lista_pos(li, 2, &alguem);
  printf("Quem é o segundo elemento: %d\n", alguem.cpf);
  buscar_lista_pos(li, 3, &alguem);
  printf("Quem é o terceiro elemento: %d\n", alguem.cpf);
  buscar_lista_pos(li, 4, &alguem);
  printf("Quem é o terceiro elemento: %d\n", alguem.cpf);
  printf("tamanho da lista antes de remover repetidos: %d\n\n", tamanho_lista(li));

  remover_repetidos(li, &l2);
  //Olhando os elementos da lista l2
  printf("Operação de remoção de repetidos funcionou lista l2\n");
  buscar_lista_pos(&l2, 1, &alguem);
  printf("Quem é o primeiro elemento: %d\n", alguem.cpf);
  buscar_lista_pos(&l2, 2, &alguem);
  printf("Quem é o segundo elemento: %d\n", alguem.cpf);
  int ok = buscar_lista_pos(&l2, 3, &alguem);
  if(ok)
    printf("Quem é o terceiro elemento: %d\n", alguem.cpf);
  printf("tamanho da lista depois de remover repetidos: %d\n\n", tamanho_lista(&l2));
  

  //UTILIZADOS PARA TESTAR INVERSÃO DE LISTA

  // //olhando os elementos da lista Li
  // printf("Mostrando li:\n");
  // buscar_lista_pos(li, 1, &alguem);
  // printf("Quem é o primeiro elemento: %d\n", alguem.cpf);
  // buscar_lista_pos(li, 2, &alguem);
  // printf("Quem é o segundo elemento: %d\n\n", alguem.cpf);

  // //Olhando os elementos da lista l2
  // int x = inverter_lista(li, &l2);
  // printf("Operação funcionou: %d\n", x);
  // buscar_lista_pos(&l2, 1, &alguem);
  // printf("Quem é o primeiro elemento: %d\n", alguem.cpf);
  // buscar_lista_pos(&l2, 2, &alguem);
  // printf("Quem é o segundo elemento: %d\n\n", alguem.cpf);


  // int x = inserir_inicio(li, human);
  // printf("Inserção no inicio da lista: %d\n", x);
  // int u = inserir_inicio(li, human); //inserção de dois elementos
  // printf("Inserção no inicio da lista: %d\n", u);
  // int y = inserir_final(li, human);
  // printf("Inserção no fim da lista: %d\n", y);
  // int z = inserir_meio(li, human);
  // printf("Inserção no meio da lista: %d\n", z);
  // printf("\n\n");

  // int t = remover_inicio(li);
  // printf("Remoção no inicio da lista: %d\n", t);
  // int w = remover_fim(li);
  // printf("Remoção no fim da lista: %d\n", w);
  // int k = remover_meio(li, human.cpf);
  // printf("Remoção no meio da lista: %d\n", k);
  // printf("\n\n");

  // int j = tamanho_lista(li);
  // printf("tamanho da lista: %d\n", j);
  // int n = lista_cheia(li);
  // printf("Lista cheia: %d\n", n);
  // int a = lista_vazia(li);
  // printf("Lista vazia: %d\n", a);
  // int h = buscar_lista_valor(li, human.cpf, &alguem);
  // printf("Consultar na lista valor: %d\n", h);
  // printf("%d\n", alguem.cpf);
  // int p = buscar_lista_pos(li, 1, &alguem);
  // printf("Consultar na lista posição: %d\n", p);
  // printf("%d\n", alguem.cpf);



  //destruir_lista(li);
  return 0;
}