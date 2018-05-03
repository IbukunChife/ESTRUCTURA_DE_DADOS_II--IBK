#include <stdio.h>
#include <stdlib.h>
#include "Arv.h"

int main() {
    ArvBin * Pai= criar_arvore();
    Lista* Colunas= criar_Lista();
    int N ,valor;
    bool escolher = true;
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
    while (escolher){
        int a, fim;
        printf("Se Desejar Imprirmir la lista total do numero de No por Niveis Aperta (0)\n");
        printf("Se Desejar Imprirmir pesquisar no Nivel X Aperta (1)\n");
        scanf("%d",&a);
        if (a==0){
            printf("Imprimindo Os numéros de No Por Niveis.\n");
            printf("Temos em Total %d Colunas.\n",Colunas->tam);
            printf("As Colunas aumentam em Profundidade.\n");
            for(No* aus= Colunas->ini; aus!=NULL; aus=aus->prox){
                printf("Coluna: %d => Numero de No: %d\n",aus->numero_coluna,aus->numero_de_No);
            }
        }
        if (a==1){
            int nivel;
            printf("Digite o Nivel Desejado\n");
            scanf("%d",&nivel);
            Procurar_numero_de_no_arvore(Pai,nivel);
        }
        printf("Se Desejar Terminar o Programa Aperta (2)\n se Desejar Continuar Digite Qualquer numero\n");
        scanf("%d",&fim);
        if (fim == 2 )
            escolher=false;
    }

    liberar_Lista(Colunas);
    libera_arv(Pai);
    return 0;
}