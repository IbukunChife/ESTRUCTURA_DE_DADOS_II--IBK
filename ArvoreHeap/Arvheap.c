//
// Created by WizIbk on 14/06/18.
//
#include <stdio.h>
#include <stdlib.h>
#include "Arvheap.h"
#include <limits.h>

int Parent(int i) {
    return i % 2 > 0 ? (i / 2) : (i / 2) + 1;
}

int Left(int i) {
    return 2 * i;
}

int Right(int i) {
    return (2 * i) + 1;
}

Heap *criar_heap(int n) {
    Heap *novo = (Heap *) malloc(sizeof(Heap));
    novo->size = n;
    novo->vet = (int *) malloc((n + 1) * sizeof(int));
    return novo;
}

void insere_heap(Heap *H) {
    printf("Digite os valores");
    for (int i = 1; i <= H->size; i++)
        scanf("%d", &H->vet[i]);
}

void Max_heapify(Heap *H, int i) {
    int largest;
    int l = Left(i);
    int r = Right(i);
    if (l <= H->size && H->vet[l] > H->vet[i])
        largest = l;
    else
        largest = i;
    if (r <= H->size && H->vet[r] > H->vet[largest])
        largest = r;
    if (largest != i) {
        int aus = H->vet[i];
        H->vet[i] = H->vet[largest];
        H->vet[largest] = aus;
        Max_heapify(H, largest);
    }
}

void Build_Max_Heap(Heap *H) {
    H->heap_size = H->size;
    for (int i = H->size / 2; i >= 1; i--)
        Max_heapify(H, i);
}

void HeapSort(Heap *H) {
    Build_Max_Heap(H);
    for (int i = H->size; i <= 2; i--) {
        int aus = H->vet[1];
        H->vet[1] = H->vet[i];
        H->vet[i] = aus;
        H->heap_size--;
        Max_heapify(H,1);
    }
}

int Heap_Maximum(Heap* H){
    return H->vet[1];
}

int Heap_Extract_Max(Heap* H){
    if (H->heap_size < 1){
        printf("error\" Heap Underflow\" \n");
    }
    int max = H->vet[1];
    H->vet[1] = H->vet[H->heap_size];
    H->heap_size--;
    Max_heapify(H,1);
    return max;
}

int Heap_Increase_Key(Heap* H,int i , int key){
    if (key < H->vet[i])
        printf("error \"o novo valor esta menor que o presente valor\"\n");
    H->vet[i] = key;
    while ( i>1 && H->vet[Parent(i)]<H->vet[i]){
        int aus = H->vet[i];
        H->vet[i]= H->vet[Parent(i)];
        H->vet[Parent(i)]= aus;
        i= Parent(i);
    }
    return 0;
}

int Max_Heap_Insert(Heap* H,int key){
    H->heap_size ++;
    H->vet[H->heap_size]= INT_MIN;
    Heap_Increase_Key(H, H->heap_size, key);
}

void Print_Heap(Heap* H){
    for(int i = 1; i<= H->size; i++){
        printf(" %d",H->vet[i]);
    }
}