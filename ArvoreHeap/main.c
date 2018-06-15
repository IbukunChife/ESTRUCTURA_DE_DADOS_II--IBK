#include <stdio.h>
#include <stdlib.h>
#include "Arvheap.h"

int main() {
    int n;
    Heap* One = (Heap*)malloc(sizeof(Heap));
    printf("Digite o numero de elemento\n");
    scanf("%d",&n);
    One = criar_heap(n);
    insere_heap(One);
    Build_Max_Heap(One);
    Print_Heap(One);
    return 0;
}