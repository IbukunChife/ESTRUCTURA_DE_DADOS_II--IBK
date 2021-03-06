#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>

using namespace std;

typedef struct SegLazy {
    int size;
    int *vet;
    int *segTreeMin;
    int *segTreeMax;
    int seglen;
} Tree;

bool Potencia2(int k) { // se lg maio que lg1 nao é potencia ### se for iguais é potencia
    double lg = log10(k) / log10(2);
    int lg1 = (int) lg;
    return lg == lg1;
}

int Prox_Potencia2(int k) {
    int n = k + 1;
    if (Potencia2(n))
        return n;
    else
        Prox_Potencia2(n);
}

int min(int x, int y) {
    return x<y ? x : y ;
}

int max(int x, int y) {
    return x>y ? x : y ;
}


Tree *criar_Tree(int tam) {
    Tree *novo = (Tree *) malloc(sizeof(Tree));
    novo->size = tam;
    if (Potencia2(tam)) {
        novo->seglen = 2*tam-1;
        novo->segTreeMin = (int *) malloc((2 * tam - 1) * sizeof(int));
        novo->segTreeMax = (int *) malloc((2 * tam - 1) * sizeof(int));
    } else {
        int n = Prox_Potencia2(tam);
        novo->seglen = 2*n-1;
        novo->segTreeMin = (int *) malloc((2 * n - 1) * sizeof(int));
        novo->segTreeMax = (int *) malloc((2 * n - 1) * sizeof(int));
    }
    for (int i = 0; i<novo->seglen;i++){
        novo->segTreeMin[i] = INT_MAX;
        novo->segTreeMax[i] = INT_MAX;
    }
    novo->vet = (int *) malloc(tam + 1 * sizeof(int));
    return novo;
}


void buildsegTree(Tree *Arv, int low, int high, int pos) {

    if (low == high) {
        Arv->segTreeMin[pos] = Arv->vet[low];
        Arv->segTreeMax[pos] = Arv->vet[low];

    } else {
        int mid = (low + high) / 2;
        buildsegTree(Arv, low, mid, 2 * pos + 1);
        buildsegTree(Arv, mid + 1, high, 2 * pos + 2);
        Arv->segTreeMin[pos] = min(Arv->segTreeMin[2 * pos + 1], Arv->segTreeMin[2 * pos + 2]);
        Arv->segTreeMax[pos] = max(Arv->segTreeMax[2 * pos + 1], Arv->segTreeMax[2 * pos + 2]);

    }
}

int searchMinimum(Tree *Arv, int low, int high, int qlow, int qhigh, int pos) {

    if (qlow <= low && qhigh >= high) {
        return Arv->segTreeMin[pos];
    }
    if (qlow > high || qhigh < low) {
        return INT_MAX;
    }
    int mid = (low + high) / 2;
    return min(searchMinimum(Arv, low, mid, qlow, qhigh, 2 * pos + 1),
               searchMinimum(Arv, mid + 1, high, qlow, qhigh, 2 * pos + 2));
}

int searchMaximum(Tree *Arv, int low, int high, int qlow, int qhigh, int pos) {

    if (qlow <= low && qhigh >= high) {
        return Arv->segTreeMax[pos];
    }
    if (qlow > high || qhigh < low) {
        return INT_MIN;
    }
    int mid = (low + high) / 2;
    return max(searchMaximum(Arv, low, mid, qlow, qhigh, 2 * pos + 1),
               searchMaximum(Arv, mid + 1, high, qlow, qhigh, 2 * pos + 2));
}

void liberar(Tree* Arv){
    free(Arv->segTreeMin);
    free(Arv->segTreeMax);
    free(Arv->vet);
    free(Arv);
}

int main() {
    int N, q;

    while ((scanf("%d", &N))!= EOF) {
        Tree *Pai = criar_Tree(N);
        for (int a = 1; a <= N; a++)
            scanf("%d", &Pai->vet[a]);
        scanf("%d", &q);
        for (int b = 0; b < q; b++) {
            int aus;
            scanf("%d", &aus);
            if (aus == 1) {
                int i, p;
                scanf("%d %d", &i, &p);
                Pai->vet[i] = p;
                buildsegTree(Pai, 1, N, 0);
            }
            if (aus == 2) {
                int i, j;
                scanf("%d %d", &i, &j);
                buildsegTree(Pai, 1, N, 0);
                int dif_preco = searchMaximum(Pai, 1, N, i, j, 0) - searchMinimum(Pai, 1, N, i, j, 0);
                printf("%d\n", dif_preco);
            }

        }
        liberar(Pai);
    }
    return 0;
}