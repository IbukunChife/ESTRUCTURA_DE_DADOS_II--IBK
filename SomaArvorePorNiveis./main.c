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
    printf("Imprimindo as Somas Por Niveis.\n");
    printf("Temos em Total %d Colunas.\n",Colunas->tam);
    printf("As Colunas aumentam em Profundidade.\n");
    for(No* aus= Colunas->ini; aus!=NULL; aus=aus->prox){
        printf("Coluna: %d => Soma: %d\n",aus->numero_coluna,aus->soma);
    }
    liberar_Lista(Colunas);
    libera_arv(Pai);
    return 0;
}