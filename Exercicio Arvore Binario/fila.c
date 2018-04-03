//
// Created by IBK on 25/03/18.
//
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Fila* criar_fila(){
    Fila* f = (Fila *)malloc(sizeof(Fila));
    f->fim =f->ini=NULL;
    f->tam = 0;
    return f;
}
void  inserir_fila (Fila* f ,Nodo* raiz){
    Lista * novo =(Lista *)malloc(sizeof(Lista));
    novo->raiz = raiz;
    novo->prox = NULL;
    if(f->fim!= NULL){
        f->fim->prox=novo;
    } else{
        f->ini = novo;
    }
    f->fim= novo;
    f->tam++;
}

Nodo* retirar_fila(Fila* f){
    Lista* aux;
    Nodo* end;
    if(fila_vazia(f)){
        printf("Fila vazia.\n");
        exit(1);
    }
    aux = f->ini;
    end = aux->raiz;
    f->ini =  aux->prox;
    if (f->ini == NULL){
        f->fim = NULL;
    }
    f->tam--;
    free(aux);
    return end;
}

int fila_vazia(Fila* f ){
    return (f->tam == 0);
}

void liberar_fila(Fila * f){
    Lista* q = f->ini;
    while(q!=NULL){
        Lista* t = q->prox;
        free(q);
        q= t;
    }
    free(f);
}