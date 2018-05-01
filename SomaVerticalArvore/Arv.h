//
// Created by WizIbk on 26/04/18.
//

#ifndef SOMAVERTICALARVORE_ARV_H
#define SOMAVERTICALARVORE_ARV_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//////////////LISTA***--STRUCT//////////////////////////////
typedef struct noo {
    int numero_coluna;
    int  soma;
    struct noo * prox;
}No;

typedef struct lista{
    No* ini;
    No* fim;
    int tam;
}Lista;

///ARVORE
typedef struct no{
    int valor;
    int coluna;
    struct no * esq;
    struct no * dir;
}Nodo;

typedef struct arvore{
    Nodo* raiz;
}ArvBin;
ArvBin* criar_arvore();
Nodo* criar_no( int info,Lista*l,int col);
void inserir_arvore(ArvBin* arv, int i,Lista* l);
static Nodo* inserir_no(Nodo* raiz,int k,Lista* l,int col);
void imprimir_arvore(ArvBin * arv);
void imprimir_In_ordem(Nodo * arv);
void libera_arv(ArvBin* arv);
void libera_no(Nodo* raiz);

//////////////////////////////LISTA~FUNÇÃO//////////////////////////////////////////////
Lista* criar_Lista();
void  inserir_Lista (Lista* f ,int numero);
void somar_coluna(Lista* l, Nodo*  raiz);
bool verificar_coluna(Lista* l, int numero);
void liberar_Lista(Lista * l);


#endif //SOMAVERTICALARVORE_ARV_H
