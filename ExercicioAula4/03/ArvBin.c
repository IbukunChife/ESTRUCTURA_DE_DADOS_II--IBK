//
// Created by IBK on 12/04/18.
//

#include <stdio.h>
#include <stdlib.h>
#include "ArvBin.h"

ArvBin* criar_arvore(Nodo * raiz){
    ArvBin* Pai = (ArvBin*)malloc(sizeof(ArvBin));
    Pai->raiz= raiz;
    return Pai;
}

Nodo* criar_no( int info, Nodo* esq, Nodo* dir){
    Nodo* novo = (Nodo *)malloc (sizeof(Nodo));
    novo->valor = info;
    novo->esq = esq;
    novo->dir = dir;
    return  novo;
}

void libera_no(Nodo* raiz){
    if(raiz != NULL){
        libera_no(raiz->esq);
        libera_no(raiz->dir);
        free(raiz);
    }
}

void libera_arv(ArvBin* arv){
    libera_no(arv->raiz);
    free(arv);
}

