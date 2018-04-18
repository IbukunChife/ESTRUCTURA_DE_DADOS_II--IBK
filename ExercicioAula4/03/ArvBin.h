//
// Created by IBK on 12/04/18.
//

#ifndef EXERCICIOEMSALA_ARVBIN_H
#define EXERCICIOEMSALA_ARVBIN_H

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

ArvBin* criar_arvore(Nodo * raiz);
Nodo* criar_no( int info, Nodo* esq, Nodo* dir);
void libera_arv(ArvBin* arv);
void libera_no(Nodo* raiz);



#endif //EXERCICIOEMSALA_ARVBIN_H
