//
// Created by WizIbk on 14/06/18.
//

#ifndef ARVOREHEAP_ARVHEAP_H
#define ARVOREHEAP_ARVHEAP_H

typedef struct Arvheap{
    int size;
    int heap_size;
    int* vet;
}Heap;

Heap *criar_heap(int n);
int Parent(int i);
int Left(int i);
int Right(int i);
void insere_heap(Heap* H);
void Max_heapify(Heap*H,int i);
void Build_Max_Heap(Heap* H);
void HeapSort(Heap* H);
int Heap_Maximum(Heap* H);
int Heap_Extract_Max(Heap* H);
int Heap_Increase_Key(Heap* H,int i , int key);
void Print_Heap(Heap* H);




#endif //ARVOREHEAP_ARVHEAP_H
