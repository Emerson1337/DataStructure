#include <stdio.h>
#include "pilha_dinamica.h"

int main(void) {
  int numbers[11] = {4,6,3,8,6,19,13,11,23,21,45};
  Pilha *pi;
  pi = ordernar_pilha(numbers, 11);
  mostrar_por_idade(pi);

  // char teste[20] = ")(-))))-((((-(-)";
  // int k = verificar_expressão(teste);
  

  
  // Pilha *pi;
  // Pilha *pi2;
  // Pessoa alguem;
  // Pessoa alguem2;
  // Pessoa alguem3;
  // Pessoa consultado;


  // alguem.cpf = 99999999;
  // alguem.idade = 19;

  // alguem2.cpf = 12345678;
  // alguem2.idade = 43;

  // alguem3.cpf = 66666666;
  // alguem3.idade = 20;



  // pi = criar_pilha();
  // printf("Pilha criada com sucesso\n");
  // int x = inserir_pilha(pi, alguem);
  // printf("Operação de inserção pilha: %d\n", x);
  // int y = inserir_pilha(pi, alguem2);
  // printf("Operação de inserção pilha: %d\n\n", y);
  // int h = inserir_pilha(pi, alguem3);
  // printf("Operação de inserção pilha: %d\n\n", h);

  // mostrar(pi);

  // pi = ordernar_pilha(pi);
  // mostrar(pi);



  //criando e inserindo os mesmos elementos na pilha2
  // pi2 = criar_pilha();
  // inserir_pilha(pi2, alguem);
  // inserir_pilha(pi2, alguem2);
  // int resposta = pilhas_iguais(pi, pi2);
  // printf("As pilhas são iguais: %d\n", resposta);



  // printf("*APÓS INVERTER A PILHA*\n");
  // consultar_pilha(pi, &consultado);
  // printf("CPF do consultado: %d\n\n", consultado.cpf);
  // printf("*ANTES DE INVERTER A PILHA*\n");
  // consultar_pilha(pi, &consultado);
  // printf("CPF do consultado: %d\n\n", consultado.cpf);
  // int tamanho = tamanho_pilha(pi);
  // printf("Tamanho da pilha: %d\n\n", tamanho);
  // pi = inverter_pilha(pi);
  // int z = remover_pilha(pi);
  // printf("Operação de remoção: %d\n", z);
  // int tamanho2 = tamanho_pilha(pi);
  // printf("Tamanho da pilha pós remoção: %d\n\n", tamanho2);
  // consultar_pilha(pi, &consultado);
  // printf("*APÓS REMOVER ELEMENTO*\n");
  // printf("CPF do consultado: %d\n\n", consultado.cpf);

  destruir_pilha(pi);
  return 0;
}

