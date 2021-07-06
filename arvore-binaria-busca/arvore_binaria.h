#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

typedef struct NO* ArvBin;

ArvBin* criar_arvore();
void liberar_no(struct NO* no);
void liberar_arvore(ArvBin* raiz);
int arvore_vazia(ArvBin *raiz);
int altura_arvore(ArvBin *raiz);
int total_no_arvore(ArvBin *raiz);
void preordem_arvore(ArvBin* raiz);
void emordem_arvore(ArvBin* raiz);
void posordem_arvore(ArvBin* raiz);
int inserir_arvore(ArvBin* raiz, int valor);
int remove_arvore(ArvBin *raiz, int valor);
int consultar_arvore(ArvBin *raiz, int valor);
int verificar_arvores(ArvBin *raiz, ArvBin *raiz2);
int balanceamentoNO(ArvBin *raiz);
void destruir_arvore(ArvBin *raiz);

#endif