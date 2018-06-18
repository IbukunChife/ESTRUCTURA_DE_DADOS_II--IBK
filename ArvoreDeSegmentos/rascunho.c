//
// Created by WizIbk on 15/06/18.
//
#include <stdio.h>
#include <limits.h>

#define TAM 4

int min(int x, int y){
    return (x < y) ? x : y;
}

void buildMinsegTree(int segTree[], int vet[], int low, int high, int pos){

    if(low == high){
        printf("1 POS :%d LOW: %d SEG: %d\n", pos,low, segTree[pos]);
        segTree[pos] = vet[low];
    } else {
        printf("2 POS :%d LOW: %d\n", pos,low);
        int mid = (low + high) / 2;
        buildMinsegTree(segTree, vet, low, mid, 2 * pos + 1);
        buildMinsegTree(segTree, vet, mid + 1 , high, 2 * pos + 2);
        segTree[pos] = min(segTree[2 * pos + 1], segTree[2 * pos + 2]);
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

int main() {
    int vet[TAM] = {2,3,7,5};
    int segTree[2 * TAM - 1];

    for(int i = 0; i < 2 * TAM - 1; i++){
        segTree[i] = -1;
    }

    buildMinsegTree(segTree,vet, 0, TAM - 1, 0);

    for(int i = 0; i < 2 * TAM - 1; i++){
        printf("%d ", segTree[i]);
    }

    return 0;
}
