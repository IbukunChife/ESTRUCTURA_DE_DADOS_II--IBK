#include <stdio.h>
#include "HRNTree.h"
#include <math.h>
#include <time.h>
#include <stdlib.h>


int main() {
    int tam;
    printf("digite 0o tamanho da Tabela Hash\n");
    scanf("%d",&tam);
     HRNTree * Pai = criar_tab(tam);
     for (int i = 0; i < (tam*5);i++){
         int chave =  rand() % 100;
         inserir_No_Tab(Pai,chave);
     }
     imprimir_Tab(Pai);
    return 0;
}