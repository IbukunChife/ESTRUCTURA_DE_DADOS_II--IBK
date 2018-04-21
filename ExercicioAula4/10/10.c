//
// Created by IBK on 16/04/18.
//

#include <stdio.h>
#include <stdlib.h>
#include "ArvBinBusca.h"
#include <stdbool.h>
#include <limits.h>


bool Verificar (int * lista1 ,int * lista2, int tam_1, int tam_2){
    int j =0, cont=0;
    for (int i =0;i<tam_1;i++){
        if (lista1[i] == lista2[j]){
            if(cont==j && (j<tam_2)){
                cont++;
                j++;
                if(j==tam_2)
                    return true;
                if (lista1[i+1] != lista2[j])
                    return false;
            }
        }
    }
}

int main (){
    int tam_1,tam_2, info;
    int * lista_sub; int * lista_arv;
    bool flag =0;
    while (!flag) {
        // Primeira Arvore
        printf ("\nCRIANDO A PRIMEIRA ARVORE\n");
        ArvBin *Pai_1 = criar_arvore ();
        printf ("Digite o numero No da arvore Binario de Busca. \n");
        scanf ("%d" , &tam_1);
        printf ("Entre os valores \n");
        for ( int i = 0 ; i < tam_1 ; i++ ){
            scanf ("%d" , &info);
            inserir_arvore (Pai_1 , info);
        }
        lista_arv = listar_arvore (Pai_1,tam_1);
        // subsequência
        printf ("Digite o numero de elemento da subsequência.\n");
        scanf ("%d" , &tam_2);
            lista_sub = (int*)malloc (tam_2*sizeof (int));
        printf ("\n Entre uma subsequência ordenada.\n");
        for ( int i = 0 ; i < tam_2 ; i++ ) {
            scanf ("%d" , &lista_sub[i]);
        }
        if (tam_1<tam_2)
            printf ("As subsequências não faz parte da Arvore Binaria de Busca.\n");
        else if (Verificar(lista_arv,lista_sub, tam_1,tam_2))
            printf ("As subsequências faz parte da Arvore Binaria de Busca.\n");
        else
            printf ("As subsequência não faz parte da Arvore Binaria de Busca.\n");
        libera_arv (Pai_1);
        printf ("\nDigite 1- para Sair 0- para continuar\n");
        scanf ("%d",&flag);
    }
}