#include <stdio.h>
#include "pilha_estatica.h"

int main(void) {
  Pilha *pi;
  Pessoa alguem;
  Pessoa alguem2;
  Pessoa consultado;

  alguem.cpf = 12345678;
  alguem.idade = 19;

  alguem2.cpf = 99999999;
  alguem2.idade = 43;


  pi = criar_pilha();
  printf("Pilha criada com sucesso\n");
  int x = inserir_pilha(pi, alguem);
  printf("Operação de inserção: %d\n", x);
  int y = inserir_pilha(pi, alguem2);
  printf("Operação de inserção: %d\n\n", y);

  consultar_pilha(pi, &consultado);
  printf("CPF do consultado: %d\n\n", consultado.cpf);

  int tamanho = tamanho_pilha(pi);
  printf("Tamanho da pilha: %d\n", tamanho);
  int z = remover_pilha(pi);
  printf("Operação de remoção: %d\n", z);
  int tamanho2 = tamanho_pilha(pi);
  printf("Tamanho da pilha pós remoção: %d\n\n", tamanho2);
  consultar_pilha(pi, &consultado);
  printf("*APÓS REMOVER ELEMENTO*\n");
  printf("CPF do consultado: %d\n\n", consultado.cpf);

  destruir_pilha(pi);
  return 0;
}