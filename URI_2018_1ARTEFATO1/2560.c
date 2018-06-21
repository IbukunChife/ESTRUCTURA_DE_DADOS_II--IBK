#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min(int x, int y){
    return (x < y) ? x : y;
}

int maior(int x, int y){
    return (x > y) ? x : y;
}
//ÁRVORE DE SEGMENTO QUE ENCONTRA O MENOR
void buildMinsegTree(long long int segTree[], int vet[], int low, int high, int pos){

    if(low == high){
        segTree[pos] = vet[low];
    } else {
        int mid = (low + high) / 2;
        buildMinsegTree(segTree, vet, low, mid, 2 * pos + 1);
        buildMinsegTree(segTree, vet, mid + 1 , high, 2 * pos + 2);
        segTree[pos] = min(segTree[2 * pos + 1], segTree[2 * pos + 2]);
    }
}

//ÁRVORE DE SEGMENTO QUE ENCORNTRA O MAIOR
void buildMaxsegTree(long long int segTree[], int vet[], int low, int high, int pos){

    if(low == high){
        segTree[pos] = vet[low];
    } else {
        int mid = (low + high) / 2;
        buildMaxsegTree(segTree, vet, low, mid, 2 * pos + 1);
        buildMaxsegTree(segTree, vet, mid + 1 , high, 2 * pos + 2);
        segTree[pos] = maior(segTree[2 * pos + 1], segTree[2 * pos + 2]);
    }
}

//ÁRVORE DE SEGMENTO DA SOMA
long long int buildsegTreeSoma(long long int segTree[], int vet[], int low, int high, int pos){

    if(low == high){
        segTree[pos] = vet[low];
        return vet[low];
    } else {
        int mid = (low + high) / 2;
        int somaEsq = buildsegTreeSoma(segTree, vet, low, mid, 2 * pos + 1);
        int somaDir = buildsegTreeSoma(segTree, vet, mid + 1 , high, 2 * pos + 2);
        segTree[pos] = somaEsq + somaDir;
        return segTree[pos];
    }
}

//BUSCA EM UMA ARVORE DE SEGMENTO
long long int searchMinimum(long long int segTree[], int low, int high, int qlow, int qhigh, int pos){

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

long long int searchMaximum(long long int segTree[], int low, int high, int qlow, int qhigh, int pos){

    if(qlow <= low && qhigh >= high){
        return segTree[pos];
    }
    if(qlow > high || qhigh < low){
        return INT_MIN;
    }
    int mid = (low + high) / 2;
    return maior(searchMaximum(segTree, low, mid, qlow, qhigh, 2 * pos + 1),
               searchMaximum(segTree, mid + 1, high, qlow, qhigh, 2 * pos + 2));
}

long long int searchSoma(long long int segTree[], int low, int high, int qlow, int qhigh, int pos){

    if(qlow <= low && qhigh >= high){
        return segTree[pos];
    }
    if(qlow > high || qhigh < low){
        return 0;
    }
    int mid = (low + high) / 2;
    int somaEsq = searchSoma(segTree, low, mid, qlow, qhigh, 2 * pos + 1);
    int somaDir = searchSoma(segTree, mid + 1, high, qlow, qhigh, 2 * pos + 2);
    return somaEsq + somaDir;
}

int main() {
    long long int segTreeMin[800000];
    long long int segTreeMax[800000];
    long long int segTreeSoma[800000];
    int vet[800000];
    int i, v, tam_segTree;
    int TAM, b;

    long long int somaTotal;
    long long int somaMin;
    long long int somaMax;
    long long int score;

    while(scanf("%d %d", &TAM, &b) != EOF){

        somaTotal = 0;
        somaMin = 0;
        somaMax = 0;
        score = 0;

        for(i = 0; i < TAM; i++){
            scanf("%d", &v);
            vet[i] = v;
        }

        buildMinsegTree(segTreeMin, vet, 0, TAM - 1, 0);
        buildMaxsegTree(segTreeMax, vet, 0, TAM - 1, 0);
        buildsegTreeSoma(segTreeSoma, vet, 0, TAM - 1, 0);

        for(i=0; i<=TAM-b; i++){
            int qhigh = b-1+i;

            somaTotal += searchSoma(segTreeSoma, 0, TAM - 1, i, qhigh, 0);
            somaMin += searchMinimum(segTreeMin, 0, TAM - 1, i, qhigh, 0);
            somaMax += searchMaximum(segTreeMax, 0, TAM - 1, i, qhigh, 0);
        }

        score = somaTotal - (somaMin + somaMax);

        printf("%lld\n", score);
    }
    return 0;
}
