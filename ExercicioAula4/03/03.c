//
// Created by IBK on 12/04/18.
//
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "ArvBin.h"
#include <stdbool.h>

bool verificar(Nodo* raiz){
   int  cont=0;
    if(raiz->esq != NULL && raiz->dir == NULL){
        if(raiz->valor > (raiz->esq)->valor ){
            cont ++;
        }
        return cont == 1 ? true : false ;
    }
    if(raiz->esq == NULL && raiz->dir != NULL){
        if(raiz->valor < (raiz->dir)->valor ){
            cont ++;
        }
        return cont == 1 ? true : false ;
    }
    if(raiz->esq == NULL && raiz->dir == NULL){
        return true;
    }
    if(raiz->esq != NULL && raiz->dir != NULL){

        if(raiz->valor < (raiz->dir)->valor ){
            cont ++;
        }
        if(raiz->valor > (raiz->esq)->valor ){
            cont ++;
        }
        if (cont==2)
            return true;
        else
            return false;

    }
}


bool Verificar_ArvBB_NO(Nodo* raiz,int min , int max){
    while(raiz != NULL){
        if ( verificar(raiz) && (raiz->valor > min && raiz->valor < max) ){
            Verificar_ArvBB_NO(raiz->esq,min,raiz->valor);
            Verificar_ArvBB_NO(raiz->dir, raiz->valor,max);
            return true;
        }else{
            return false;
        }
    }
}
bool Verificar_ArvBB(ArvBin* arv){
    return Verificar_ArvBB_NO (arv->raiz,INT_MIN,INT_MAX);
}
int main (){
    int tam, info;
  //  while () {  }
    ArvBin *Pai = criar_arvore (
            criar_no('a',
                     criar_no('b',criar_no('d',NULL,NULL),
                              criar_no('e',NULL,criar_no('h',NULL,NULL))),
                     criar_no('c',criar_no('f',criar_no('i',criar_no('j',NULL,NULL),NULL),NULL),
                              criar_no('g',NULL,NULL)))
    );
        if ( Verificar_ArvBB (Pai))
            printf ("A arvore é de Busca Binaria");
        else
            printf ("A arvore Não é de Busca Binaria");
        libera_arv (Pai);

}

