//
// Created by IBK on 16/04/18.
//

#include <stdio.h>
#include <stdlib.h>
#include "ArvBinBusca.h"
#include <stdbool.h>


int main (){
    int tam, info, position;
    bool flag =0;
    while (!flag) {
        ArvBin *Pai = criar_arvore ();
        printf ("Digite o numero de valor a entrar na arvore Binario de Busca \n");
        scanf ("%d" , &tam);
        printf ("Digite os valores \n");
        for ( int i = 0 ; i < tam ; i++ ) {
            scanf ("%d" , &info);
            inserir_arvore (Pai , info);
        }
        printf ("\nDigite a posição do K_sieme Desejado \n");
        scanf ("%d",&position);
        k_esimo (Pai,position);
        printf ("\nImprimindo a arvore para conferir \n");
        imprimir_arvore (Pai);
        printf ("\n");
        printf ("\nDigite 1- para Sair 0- para continuar\n");
        scanf ("%d",&flag);

        libera_arv (Pai);
    }
}
