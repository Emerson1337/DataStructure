#include <stdio.h>
#include "arvore_binaria.h"

int main(void) {
  ArvBin* arvore = criar_arvore();
  //inserindo elementos
  inserir_arvore(arvore, 25);
  inserir_arvore(arvore, 10);
  inserir_arvore(arvore, 8);
  inserir_arvore(arvore, 3);
  inserir_arvore(arvore, 1);
  inserir_arvore(arvore, 15);
  inserir_arvore(arvore, 75);
  inserir_arvore(arvore, 17);
  inserir_arvore(arvore, 30);
  inserir_arvore(arvore, 28);
  inserir_arvore(arvore, 27);
  inserir_arvore(arvore, 52);
  inserir_arvore(arvore, 70);
  inserir_arvore(arvore, 65);
  inserir_arvore(arvore, 73);

  // removendo elementos
  remove_arvore(arvore, 28);
  remove_arvore(arvore, 15);
  remove_arvore(arvore, 75);
  remove_arvore(arvore, 1);

  posordem_arvore(arvore);
  // preordem_arvore(arvore);

  // inserir_arvore(arvore2, 25);
  // inserir_arvore(arvore2, 10);
  // inserir_arvore(arvore2, 8);
  // inserir_arvore(arvore2, 3);
  // inserir_arvore(arvore2, 1);
  // inserir_arvore(arvore2, 15);
  // inserir_arvore(arvore2, 75);
  // inserir_arvore(arvore2, 17);
  // inserir_arvore(arvore2, 30);
  // inserir_arvore(arvore2, 28);
  // inserir_arvore(arvore2, 27);
  // inserir_arvore(arvore2, 52);
  // inserir_arvore(arvore2, 70);
  // inserir_arvore(arvore2, 65);
  // inserir_arvore(arvore2, 73);

  // int x = verificar_arvores(arvore, arvore2);
  // printf("%d\n", x);

  // int y = balanceamentoNO(arvore);
  // printf("%d\n", y);

  // remove_arvore(arvore, 10);
  // int w = consultar_arvore(arvore, 8);
  // printf("O elemento esta na arvore: %d\n", w);
  // printf("Preordem:\n");
  // preordem_arvore(arvore);
  // printf("Posordem:\n");
  // posordem_arvore(arvore);
  // printf("emordem:\n");
  // emordem_arvore(arvore);
  // int altura = altura_arvore(arvore);
  // printf("Altura da arvore: %d\n", altura);
  // inserir_arvore(arvore, 25);
  // inserir_arvore(arvore, 8);
  // int x = verificar_arvores(arvore, arvore2);
  // printf("Arvores iguais: %d\n", x);
  // int y = balanceamentoNO(arvore);
  // printf("Arvore balanceada: %d\n", y);
  // destruir_arvore(arvore);
  return 0;
}