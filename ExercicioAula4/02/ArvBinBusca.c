//
// Created by IBK on 12/04/18.
//

#include <stdio.h>
#include <stdlib.h>
#include "ArvBinBusca.h"

ArvBin* criar_arvore(){
    ArvBin* Pai = (ArvBin*)malloc(sizeof(ArvBin));
    Pai->raiz= NULL;
    return Pai;
}

Nodo* criar_no( int info){
    Nodo* novo = (Nodo *)malloc (sizeof(Nodo));
    novo->valor = info;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
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

Nodo* busca(Nodo* raiz, int k){
    while(raiz!=NULL && raiz->valor !=k){
        if (k<raiz->valor){
            raiz= raiz->esq;
        } else{
            raiz= raiz->dir;
        }
    }
    return raiz;
}
void inserir_arvore(ArvBin* arv, int i){
    arv->raiz = inserir_no (arv->raiz, i);
}

static Nodo* inserir_no(Nodo* raiz,int k){
    if (raiz==NULL){
       raiz = criar_no (k);
    }else if (k < raiz->valor){
        raiz->esq = inserir_no (raiz->esq,k);
    }else
        raiz->dir = inserir_no (raiz->dir,k);
    return raiz;

}

int  verificar_filho(Nodo* raiz){
    if(raiz->esq != NULL && raiz->dir == NULL){
        return 1;
    }
    if(raiz->esq == NULL && raiz->dir != NULL){
        return 1;
    }
    if(raiz->esq == NULL && raiz->dir == NULL){
        return 0;
    }
    if(raiz->esq != NULL && raiz->dir != NULL){
        return 2;
    }
}

void remover_arvore(ArvBin* arv,int i){
    arv->raiz = remover (arv->raiz, i);
}

Nodo* remover (Nodo* raiz , int valor){
    if (raiz == NULL){
        return NULL;
    }else if (valor < raiz->valor){
        raiz->esq = remover (raiz->esq, valor);
    }else if(valor > raiz->valor) {
        raiz->dir = remover (raiz->dir, valor);
    } else{
        int n = verificar_filho (raiz);
        if (n == 0){
            free(raiz);
            raiz = NULL;
        }
        if (n == 1){
            if(raiz->esq){
                Nodo* aus = raiz;
                raiz= raiz->esq;
                free(aus);
                // return raiz;
            } else{
                Nodo* aus = raiz;
                raiz= raiz->dir;
                free(aus);
            }
        }
        if(n == 2){
            Nodo * p = raiz->dir;
            while(p->esq!=NULL){
                p=p->esq;
            }
            raiz->valor = p->valor;
            p->valor = valor;
            raiz->dir = remover (raiz->dir,valor);

        }
    }
    return raiz;

}

void imprimir_arvore(ArvBin * Pai){
    imprimir_In_ordem (Pai->raiz);
}

void imprimir_In_ordem(Nodo * arv) {
    if ( arv != NULL) {
        imprimir_In_ordem (arv->esq);
        printf ("%d " , arv->valor);
        imprimir_In_ordem (arv->dir);
    }
}