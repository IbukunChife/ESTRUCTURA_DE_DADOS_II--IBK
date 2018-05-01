//
// Created by WizIbk on 26/04/18.
//
#include <stdio.h>
#include <stdlib.h>
#include "Avl.h"
#include <math.h>


ArvBinAvl * criar_arv(){
    ArvBinAvl* Pai = (ArvBinAvl*) malloc(sizeof(ArvBinAvl));
    Pai->raiz = NULL;
    return Pai;
}

ArvBinAvl*  arv_cria_raiz(Nodo* raiz){
    ArvBinAvl* Pai = (ArvBinAvl*) malloc(sizeof(ArvBinAvl));
    Pai->raiz = raiz;
    return Pai;
}

Nodo* criar_Nodo(int info, Nodo * esq, Nodo *dir) {
    Nodo* novo = (Nodo*) malloc(sizeof(Nodo));
    novo->alt = 0;
    novo->info = info;
    novo->esq = esq;
    novo->dir = esq;

    return novo;
}


void imprimir_arv(ArvBinAvl* arv, int escolha){ //imprimir arvore
    if(escolha == 1){
        imprimir_PreOrdem(arv->raiz);
    }
    else if(escolha == 2){
        imprimir_EmOrdem(arv->raiz);
    }
    else if(escolha == 3){
        imprimir_PosOrdem(arv->raiz);
    }
    else
        printf("valor invalido somente [1-3]\n");
    printf("\n");
}

void imprimir_PreOrdem(Nodo* raiz){

    if(raiz != NULL){
        printf("%d\n", raiz->info);
        imprimir_PreOrdem(raiz->esq);
        imprimir_PreOrdem(raiz->dir);
    }

}


void imprimir_EmOrdem(Nodo* raiz){
    if(raiz != NULL){
        imprimir_EmOrdem(raiz->esq);
        printf("%d\n", raiz->info);
        imprimir_EmOrdem(raiz->dir);
    }
}


void imprimir_PosOrdem(Nodo* raiz) {
    if(raiz != NULL){
        imprimir_PosOrdem(raiz->esq);
        imprimir_PosOrdem(raiz->dir);
        printf("%d\n", raiz->info);
    }
}

void imprimir_Arv_formatado(ArvBinAvl* arv){
    imprimir_Avr_formatado_no(arv->raiz);
    printf("\n");
}

void imprimir_Avr_formatado_no(Nodo * raiz){
    printf("<");
    if(raiz != NULL)
    {
        printf("%d", raiz->info);
        imprimir_Avr_formatado_no(raiz->esq);
        imprimir_Avr_formatado_no(raiz->dir);
    }
    printf(">");
}


void libera(ArvBinAvl* arv) { ///LIBERA
    libera_no(arv->raiz);
    free(arv);
}

void libera_no(Nodo* raiz)
{
    if(raiz != NULL)
    {
        libera_no(raiz->esq);
        libera_no(raiz->dir);
        free(raiz);
    }
}
int max(int A, int B){
    return A > B ? A:B;
}
int arv_pertence(ArvBinAvl* Pai, int c){
    return arv_pertence_no(Pai->raiz, c);
}

int arv_pertence_no(Nodo* raiz, int c)
{
    if(raiz == NULL)
        return 0;
    else
        return c== raiz->info ||
               arv_pertence_no(raiz->esq, c) ||
               arv_pertence_no(raiz->dir, c);
}


int altura(Nodo* raiz ){ ///ALTURA
    if(raiz == NULL)
        return -1;
    else
        return 1 + max(altura(raiz->esq), altura(raiz->dir));
}

int arv_altura(ArvBinAvl* arv){
    return altura(arv->raiz);
}

int alt_no(Nodo* raiz){
    if(raiz == NULL)
        return -1;
    else
        return raiz->alt;
}

int getBalance(Nodo*raiz){
    return abs(alt_no(raiz->dir) - alt_no(raiz->esq));
}

Nodo* dirRotate(Nodo*x)
{
    Nodo* y = x->esq;
    Nodo* t2 = y->dir;
    y->dir = x;
    x->esq = t2;

    x->alt = 1 + max(alt_no(x->esq), alt_no(x->dir));
    y->alt = 1 + max(alt_no(y->esq), alt_no(y->dir));

    return y;
}

Nodo* esqRotate(Nodo*x)
{
    Nodo* y = x->dir;
    Nodo* t2 = y->esq;
    y->esq = x;
    x->dir = t2;

    x->alt = 1 + max(alt_no(x->dir), alt_no(x->esq));
    y->alt = 1 + max(alt_no(y->dir), alt_no(y->esq));

    return y;
}

void insere(ArvBinAvl* arv, int k){
    insere_no(arv->raiz, k);
}

Nodo* insere_no(Nodo* r, int k)
{
    if(r == NULL)
    {
        r = criar_Nodo(k, NULL, NULL);
        return r;
    }
    else if(k > r->info)
        r->dir = insere_no(r->dir, k);
    else if(k < r->info)
        r->esq = insere_no(r->esq, k);
    else
        return r;

    ///ATUALIZANDO ALTURA E FATOR DE BALANCEAMENTO
    r->alt = 1 + max(alt_no(r->esq), alt_no(r->dir));

    int fb = getBalance(r);

    if(fb < -1 && k < r->esq->info)///LEFT LEFT CASE
        return dirRotate(r);


    if(fb < -1 && k > r->esq->info){ ///LEFT RIGHT CASE
        r->esq = esqRotate(r->esq);
        return dirRotate(r);
    }

    if(fb < 1 && k > r->dir->info)///RIGHT RIGHT CASE
        return esqRotate(r);

    if(fb < 1 && k < r->esq->info){ ///RIGHT LEFT CASE
        r->dir = dirRotate(r->dir);
        return esqRotate(r);
    }
    return r;
}

void remover_arv(ArvBinAvl* arv, int chave){
    remover(arv->raiz, chave);
}

Nodo* remover(Nodo* raiz, int chave){
    if(raiz == NULL)
        return NULL;
    else if(chave < raiz->info)
        raiz->esq = remover(raiz->esq, chave);
    else if(chave > raiz->info)
        raiz->dir = remover(raiz->dir, chave);
    else
    {

        if(raiz->dir == NULL && raiz->esq == NULL){ ///sem filhos
            free(raiz);
            return NULL;
        }
        else if(raiz->esq == NULL){ ///um filho a direita
            Nodo *aux = raiz;
            raiz = raiz->dir;
            free(aux);
        }
        else if(raiz->dir == NULL){ ///um filho a esquerda
            Nodo *aux = raiz;
            raiz = raiz->esq;
            free(aux);
        }
        else { /// tem dois filhos;
            Nodo*sus = raiz->dir;
            while(sus->dir)
                sus = sus->dir;

            raiz->info = sus->info;
            sus->info = chave;
            raiz->esq = remover(raiz->esq, chave);
        }
    }
    return raiz;
}