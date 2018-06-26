
/* Questão 2) Implemente uma tabela hash com enderaçamento aberto
 * utilizando hash duplo. As chaves deverão ser do tipo string.
 * Você pode usar a função sugerida nos slides de Tabela Hash.*/

#include <stdio.h>
#include <stdbool.h>
#include "HashD.h"

int main() {
    int size;
    bool action = 1;
    char name[20];
    printf("Digite o um numero Primo como tamanho da Tabela\n");
    scanf("%d", &size);
    HashD *Pai = criar_Tab(size);
    while (action) {
        int escolha;
        printf("Escolha a Operação desejada\n");
        printf(" 1- Inserção \n 2- Remoção \n 3- Impressão \n 4- Terminar\n");
        scanf("%d", &escolha);
        switch (escolha) {
            case 1 :
                printf("Digite o nome a Ser inserido\n");
                scanf("%s",name);
//                printf("%c\n",name[0]);
//                printf("%d\n",(int)name[0]);
                Pai = inserir_No_chaves(Pai, &name);
                break;
            case 2:
                //char name[20];
                printf("Digite o nome a Ser Removido\n");
                scanf("%s",name);
                Pai = remover_No_chaves(Pai, &name);
                break;
            case 3 :
                imprimir_Hash(Pai);
                break;
            case 4 :
                action = 0;
                break;
            default:
                printf("Digite um Valor Valido\n");
        }
        /*printf("Escolha a Operação desejada\n");
        printf(" 1- Inserção \n 2- Remoção \n 3- Impressão \n 4- Terminar\n");
        scanf("%d", &escolha);*/
    }

    liberar_Tab(Pai);
    return 0;
}