//
// Created by IBK on 16/04/18.
//
#include <stdio.h>
#include <stdlib.h>
#include "ArvBinBusca.h"
#include <stdbool.h>


int main (){
    int tam, info;
    bool flag =0;
    while (!flag) {
        ArvBin *Pai = criar_arvore ();
        printf ("Digite o numero de No da arvore Binario de Busca \n");
        scanf ("%d" , &tam);
        printf ("Entre Os valores da arvore no seu percurso Pré-Ordem \n");
        for ( int i = 0 ; i < tam ; i++ ) {
            scanf ("%d" , &info);
            inserir_arvore (Pai , info);
        }
        printf ("\nImprimindo a Arvore no seu Formato \n");
        imprimir_formato_arvBB (Pai);
        printf ("\nDigite 1- para Sair 0- para continuar\n");
        scanf ("%d",&flag);

        libera_arv (Pai);
    }
}
