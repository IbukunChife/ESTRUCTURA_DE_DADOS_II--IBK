//
// Created by WizIbk on 14/06/18.
//

#ifndef ARVOREDESEGMENTOS_SEGLAZY_H
#define ARVOREDESEGMENTOS_SEGLAZY_H

#include <stdbool.h>

typedef struct SegLazy{
    int size;
    int* vet;
    int* segTree;
    int* lazTree;
}SLTree;

SLTree* criar_SegLazy(int tam);
bool Potencia2(int k);
int Prox_Potencia2(int k);
int min(int x, int y);
void buildMinsegTree( SLTree* Arv, int low, int high, int pos)
int searchMinimum(int segTree[], int low, int high, int qlow, int qhigh, int pos);



#endif //ARVOREDESEGMENTOS_SEGLAZY_H
