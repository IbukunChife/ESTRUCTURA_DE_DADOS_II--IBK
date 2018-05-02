#include <stdio.h>
#include <stdlib.h>
#include "Arv.h"

int main() {
    ArvBin * Pai= criar_arvore();
    Lista* Colunas= criar_Lista();
    int N ,valor;
    printf("Digite o numéro de No da Arvore.\n");
    scanf("%d",&N);
    printf("Digite os valores\n");
    for (int i=0; i<N;i++){
        scanf("%d",&valor);
        inserir_arvore(Pai,valor,Colunas);
    }
    printf("Imprimindo a Arvore\n");
    imprimir_arvore(Pai);
    printf("\n");
    printf("Imprimindo Os numéros de No Por Niveis.\n");
    printf("Temos em Total %d Colunas.\n",Colunas->tam);
    printf("As Colunas aumentam em Profundidade.\n");
    for(No* aus= Colunas->ini; aus!=NULL; aus=aus->prox){
        printf("Coluna: %d => Numero de No: %d\n",aus->numero_coluna,aus->numero_de_No);
    }
    liberar_Lista(Colunas);
    libera_arv(Pai);
    return 0;
}