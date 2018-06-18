//
// Created by WizIbk on 14/06/18.
//
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "SegLazy.h"
#include <stdbool.h>
#include <math.h>

SLTree* criar_SegLazy(int tam){
    SLTree* novo = (SLTree*)malloc(sizeof(SLTree));
    novo->size = tam;
    if (Potencia2(tam))
        novo->segTree = (int*)malloc((2*tam-1)*sizeof(int));
        novo->lazTree = (int*)malloc((2*tam-1)*sizeof(int));
    else{
        int n = Prox_Potencia2(tam);
        novo->segTree = (int*)malloc((2*n-1)* sizeof(int));
        novo->lazTree = (int*)malloc((2*n-1)* sizeof(int));
    }
}

bool Potencia2(int k){ // se lg maio que lg1 nao é potencia ### se for iguais é potencia
    double lg = log10(k)/log10(2);
    int lg1 = (int)lg;
    return lg>lg1 ? false : true;
}

int Prox_Potencia2(int k){
    int n = k+1;
    if (Potencia2(n))
        return n;
    else
        Prox_Potencia2(n);
}

int min(int x, int y){
    return x < y ? x:y;
}


void buildMinsegTree( SLTree* Arv, int low, int high, int pos){

    if(low == high){
        printf("1 POS :%d LOW: %d SEG: %d\n", pos,low, Arv->segTree[pos]);
        Arv->segTree[pos] = Arv->vet[low];
    } else {
        printf("2 POS :%d LOW: %d\n", pos,low);
        int mid = (low + high) / 2;
        buildMinsegTree(Arv,low, mid, 2 * pos + 1);
        buildMinsegTree(Arv, mid + 1 , high, 2 * pos + 2);
        Arv->segTree[pos] = min(Arv->segTree[2 * pos + 1], Arv->segTree[2 * pos + 2]);
    }
}

int searchMinimum(int segTree[], int low, int high, int qlow, int qhigh, int pos){

    if(qlow <= low && qhigh >= high){
        return segTree[pos];
    }
    if(qlow > high || qhigh < low){
        return INT_MAX;
    }
    int mid = (low + high) / 2;
    return min(searchMinimum(segTree, low, mid, qlow, qhigh, 2 * pos + 1),
               searchMinimum(segTree, mid + 1, high, qlow, qhigh, 2 * pos + 2));
}

