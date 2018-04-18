//
// Created by IBK on 12/04/18.
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
    printf ("Digite o numero de valor a entrar na arvore Binario de Busca \n");
    scanf ("%d" , &tam);
    for ( int i = 0 ; i < tam ; i++ ) {
        printf ("Digite os valores \n");
        scanf ("%d" , &info);
        inserir_arvore (Pai , info);
    }
    printf ("\nImprimindo a Arvore\n");
    imprimir_arvore (Pai);
    printf ("\n Digite o Valor da arvore Que Deseja remover \n");
    scanf ("%d" , &info);
    remover_arvore (Pai, info);
    printf ("\nImprimindo a Arvore\n");
    imprimir_arvore (Pai);
    printf ("\nDigite 1- para Sair 0- para continuar\n");
    scanf ("%d",&flag);

         libera_arv (Pai);
    }
}