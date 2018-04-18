//
// Created by IBK on 16/04/18.
//
#include <stdio.h>
#include <stdlib.h>
#include "ArvBinBusca.h"
#include <stdbool.h>
#include <limits.h>

bool verificar(Nodo* raiz_1,Nodo* raiz_2){
    if (raiz_1->valor == raiz_2->valor)
        return true;
    else
        return false;

}

bool Verificar_ArvBB_Igual_NO (Nodo* raiz_1,Nodo* raiz_2){
    while(raiz_1 != NULL && raiz_2 != NULL){
        if ( verificar(raiz_1, raiz_2)){
            Verificar_ArvBB_Igual_NO (raiz_1->esq,raiz_2->esq);
            Verificar_ArvBB_Igual_NO (raiz_1->dir,raiz_2->dir);
            return true;
        }else{
            return false;
        }
    }
}
bool Verificar_ArvBB_Igual (ArvBin* arv_1 ,ArvBin* arv_2){
    return Verificar_ArvBB_Igual_NO (arv_1->raiz,arv_2->raiz);
}

int main (){
    int tam_1,tam_2, info;
    bool flag =0;
    while (!flag) {
        // Primeira Arvore
        printf ("\nCRIANDO A PRIMEIRA ARVORE\n");
        ArvBin *Pai_1 = criar_arvore ();
        printf ("Digite o numero No da arvore Binario de Busca 1. \n");
        scanf ("%d" , &tam_1);
        for ( int i = 0 ; i < tam_1 ; i++ ) {
            printf ("Digite o valor \n");
            scanf ("%d" , &info);
            inserir_arvore (Pai_1 , info);
        }
        // Segunda arvore
        printf ("\nCRIANDO A SEGUNDA ARVORE\n");
        ArvBin *Pai_2 = criar_arvore ();
        printf ("Digite o numero No da arvore Binario de Busca 2.  \n");
        scanf ("%d" , &tam_2);
        for ( int i = 0 ; i < tam_2 ; i++ ) {
            printf ("Digite o valor \n");
            scanf ("%d" , &info);
            inserir_arvore (Pai_2 , info);
        }
        if (tam_1!=tam_2)
            printf ("As arvores não são Similares.\n");
        else if ( Verificar_ArvBB_Igual (Pai_1,Pai_2))
            printf ("As arvores são Similares.\n");
        else
            printf ("As arvores não são Similares.\n");
        libera_arv (Pai_1);
        libera_arv (Pai_2);
        printf ("\nDigite 1- para Sair 0- para continuar\n");
        scanf ("%d",&flag);
    }
}
