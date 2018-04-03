//
// Created by IBK on 30/03/18.
//

#ifndef EXERCICIO_ARVORE_BINARIO_PILA_H
#define EXERCICIO_ARVORE_BINARIO_PILA_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arv_bin.h"

typedef struct list{
    Nodo* raiz ;
    struct list * prox;
    struct list * ant;
}List;

typedef struct pila{
    List* ini;
    List* fim;
    int tam;
}Pila;

Pila* criar_pila();
void push(Pila* p,Nodo* raiz);
Nodo* pop(Pila* p);
bool pila_vazia(Pila* p);
void liberar_pila(Pila* p);

#endif //EXERCICIO_ARVORE_BINARIO_PILA_H
