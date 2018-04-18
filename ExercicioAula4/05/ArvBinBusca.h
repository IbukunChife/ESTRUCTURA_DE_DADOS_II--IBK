//
// Created by IBK on 12/04/18.
//

#ifndef EXERCICIOEMSALA_ARVBINBUSCA_H
#define EXERCICIOEMSALA_ARVBINBUSCA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no{
    int valor;
    struct no * esq;
    struct no * dir;
}Nodo;

typedef struct arvore{
    Nodo* raiz;
}ArvBin;

ArvBin* criar_arvore();
Nodo* criar_no( int info);
Nodo* busca(Nodo* raiz, int k);

void inserir_arvore(ArvBin* arv, int i);
static Nodo* inserir_no(Nodo* raiz,int k);
void remover_arvore(ArvBin* arv,int i);
Nodo* remover (Nodo* raiz , int valor);
void libera_arv(ArvBin* arv);
void libera_no(Nodo* raiz);
void imprimir_arvore(ArvBin * arv);
void imprimir_In_ordem(Nodo * arv);
int verificar_filho(Nodo* raiz);
int achar_menor_valor_no(Nodo* raiz);
void achar_menor_valor_arv(ArvBin* arv);


#endif //EXERCICIOEMSALA_ARVBINBUSCA_H
