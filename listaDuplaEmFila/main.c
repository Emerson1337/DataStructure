#include <stdio.h>
#include <stdio.h>
#include "listaDuplaEmFila.h"

//PARA TESTAR CADA FUNCIONALIDADE, DESCOMENTE OS TRECHOS DE CÓDIGO ABAIXO DO COMENTÁRIO QUE O EXPLICA.

int main(void) {
  Lista *li;
  Lista l2;
  Pessoa alguem;
  Pessoa human;
  Pessoa human2;

  char nomeVar[30] = "Emerson";
  human.nome[29] = nomeVar[29];
  human.idade = 19;
  human.cpf = 99999999;

  char teste[30] = "Ana Luiza";
  human2.nome[29] = nomeVar[29];
  human2.idade = 19;
  human2.cpf = 12345678;

  //UTILIZADOS PARA TESTAR OPERAÇÕES BÁSICAS DE LISTA
  li = criar_lista();
  int x = inserir(li, human);
  printf("Inserção na lista de modo fila: %d\n", x);
  int u = inserir(li, human2); //inserção de dois elementos
  printf("Inserção na lista de modo fila: %d\n", u);


  int j = tamanho_lista(li);
  printf("tamanho da lista: %d\n", j);
  int n = lista_cheia(li);
  printf("Lista cheia: %d\n", n);
  int a = lista_vazia(li);
  printf("Lista vazia: %d\n", a);
  int h = consultar(li, &alguem);
  printf("\nConsultando lista-fila: %d\n", h);
  printf("Primeiro da lista-fila: %d\n", alguem.cpf);
  printf("Tamanho da fila-lista: %d\n", tamanho_lista(li));

  //REMOVENDO
  printf("\n*REMOVENDO ELEMENTO*\n");
  remover(li);
  int l = consultar(li, &alguem);
  printf("\nConsultando lista-fila: %d\n", l);
  printf("Primeiro da lista-fila: %d\n", alguem.cpf);
  printf("Tamanho da fila-lista: %d\n", tamanho_lista(li));

  destruir_lista(li);
  return 0;
}