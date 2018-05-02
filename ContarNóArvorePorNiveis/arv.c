//
// Created by WizIbk on 26/04/18.
//

#include <stdio.h>
#include <stdlib.h>
#include "Arv.h"

///////////////////////////////////////ARVORE///////////////////////////

ArvBin* criar_arvore(){
    ArvBin* Pai = (ArvBin*)malloc(sizeof(ArvBin));
    Pai->raiz= NULL;
    return Pai;
}

Nodo* criar_no( int info,Lista*l,int col){
    Nodo* novo = (Nodo *)malloc (sizeof(Nodo));
    novo->valor = info;
    novo->coluna = col;
    novo->esq = NULL;
    novo->dir = NULL;
    if (verificar_coluna(l,col)){
        adicionar_numero_No(l,novo);
    }else{
        inserir_Lista(l,col);
        adicionar_numero_No(l,novo);
    }
    return novo;
}

void inserir_arvore(ArvBin* arv, int i,Lista* l){
    arv->raiz = inserir_no (arv->raiz,i,l,0);
}

static Nodo* inserir_no(Nodo* raiz,int k,Lista* l,int col){
    if (raiz==NULL){
        raiz = criar_no (k,l,col);
    }else if (k < raiz->valor){
        raiz->esq = inserir_no (raiz->esq,k,l,col+1);
    }else
        raiz->dir = inserir_no (raiz->dir,k,l,col+1);
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
/////////////////////////////////////LISTA///////////////////////////////


Lista* criar_Lista(){
    Lista* f = (Lista *)malloc(sizeof(Lista));
    f->fim =f->ini=NULL;
    f->tam = 0;
    return f;
}

void  inserir_Lista (Lista* f ,int numero){
    No* novo = (No*)malloc(sizeof(No));
    novo->numero_coluna = numero;
    novo->numero_de_No = 0;
    novo->prox= NULL;
    if(f->fim!= NULL){
        f->fim->prox=novo;
    } else{
        f->ini = novo;
    }
    f->fim= novo;
    f->tam++;
}

void adicionar_numero_No(Lista* l,Nodo * raiz){
    for (No* aus= l->ini;aus !=NULL; aus= aus->prox){
        if (aus->numero_coluna == raiz->coluna){
            aus->numero_de_No ++;
            return;
        }
    }

}


bool verificar_coluna(Lista* l, int numero){
    if (l->ini == NULL){
        return false;
    }else{
        for(No * aus = l->ini; aus!=NULL; aus=aus->prox){
            if(aus->numero_coluna==numero)
                return true;
        }
        return false;
    }

}

void liberar_Lista(Lista * l){
    No* q = l->ini;
    while(q!=NULL){
        No* t = q->prox;
        free(q);
        q = t;
    }
    free(l);
}