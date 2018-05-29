#include <stdio.h>
#include "arv.h"
int main() {
    int tamanho;
    int valor, x , y;
    printf("Digite o numero de filho da Arvore B\n");
    scanf("%d",&tamanho);
    Btree* B= Criar_ArvoreB(tamanho);
    printf("Desejar inserir quando Valor\n");
    scanf("%d",&x);
    for (int i = 0; i <x ; i++){
        printf("insere o %d Valor.",(i+1));
        scanf("%d",&valor);
        Insert_Chave(B,valor);
    }

    return 0;
}