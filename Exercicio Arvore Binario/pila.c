//
// Created by IBK on 30/03/18.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pila.h"
#include "arv_bin.h"

Pila* criar_pila(){
    Pila* novo = (Pila *)malloc (sizeof (Pila));
    novo->ini = novo->fim = NULL;
    novo->tam=0;
    return novo;
}

void push(Pila* p,Nodo* raiz){
    List* novo =(List*)malloc (sizeof (List));
    novo->raiz =raiz;
    novo->prox = novo->ant = NULL;
    if((p->ini== NULL) && (p->fim==NULL)){
        p->ini = p->fim = novo;
    }else {
        novo->ant =p->fim;
        p->fim->prox=novo;
        p->fim=novo;
    }
    p->tam++;
}
Nodo* pop(Pila* p){
    List* aux;
    Nodo* end;
    if(pila_vazia (p)){
        printf("Pila vazia.\n");
        exit(1);
    }
    aux = p->fim;
    end = aux->raiz;
    p->fim =  aux->ant;
    if (p->fim == NULL){
        p->ini = NULL;
    }
    p->tam--;
    free(aux);
    return end;
}

bool pila_vazia(Pila* p){
    return (p->tam == 0);
}

void liberar_pila(Pila* p){
    List* aux= p->ini;
    while (aux!=NULL){
        List* t = aux->prox;
        free(aux);
        aux=t;
    }
    free(p);
}