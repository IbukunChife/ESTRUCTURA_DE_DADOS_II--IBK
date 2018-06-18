#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "SegLazy.h"

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