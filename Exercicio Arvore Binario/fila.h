//
// Created by IBK on 25/03/18.
//

#ifndef EXERCICIO_ARVORE_BINARIO_FILA_H
#define EXERCICIO_ARVORE_BINARIO_FILA_H

#include "arv_bin.h"

typedef struct lista {
    Nodo* raiz ;
    struct lista * prox;
}Lista;

typedef struct fila{
    Lista* ini;
    Lista* fim;
    int tam;
}Fila;

Fila* criar_fila();
void  inserir_fila (Fila* f ,Nodo* raiz);
Nodo* retirar_fila(Fila* f);
int fila_vazia(Fila* f );
void liberar_fila(Fila * f);


#endif //EXERCICIO_ARVORE_BINARIO_FILA_H
