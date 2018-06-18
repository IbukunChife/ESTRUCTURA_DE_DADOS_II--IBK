//
// Created by WizIbk on 18/06/18.
//
#include <stdio.h>
#include <stdlib.h>
#include "HRNTree.h"
#include "RubroNegra.c"

HRNTree* criar_tab(int n){
    HRNTree * novo = (HRNTree*)malloc(sizeof(HRNTree));
    novo->Tab= (ArvRbrNeg**)malloc(n* sizeof(ArvRbrNeg));
    for (int i = 0 ; i<n; i++)
        novo->Tab[i]=criar_arvore();
    novo->size = n;
    return novo;
}
void inserir_No_Tab(HRNTree * H, int chave){
     int position = chave % H->size;
     H->Tab[position]->raiz=Rb_inserir_nodo( H->Tab[position],criar_nodo(chave));
}

void remover_No_Tab(HRNTree* H, int chave){
    int position = chave % H->size;
    H->Tab[position]->raiz=Rb_remover_nodo(H->Tab[position],criar_nodo(chave));

}
void imprimir_Tab(HRNTree* H){
    int escolha;
    printf("Escolha o modo de Impressao da Arvore RB da Tabela HASH\n");
    printf(" 1- PreOrdem \n 2- EmOrdem \n 3- PosOrdem \n");
    scanf("%d",&escolha);
    switch (escolha){
        case 1 :
            imprimir_Tab_PreOrdem(H);
            break;
        case 2:
            imprimir_Tab_EmOrdem(H);
            break;
        case 3 :
            imprimir_Tab_PosOrdem(H);
            break;
        default:
            printf("Tentar Novamente\n");
    }
}
void imprimir_Tab_PreOrdem(HRNTree* H){
    for (int i =0; i< H->size; i++){
        printf("Imprimindo a Posiçao %d da Tabela\n",i);
        imprimir_Arvore_Rb(H->Tab[i],1);
        printf("\n");
    }
}
void imprimir_Tab_EmOrdem(HRNTree* H){
    for (int i =0; i< H->size; i++){
        printf("Imprimindo a Posiçao %d da Tabela\n",i);
        imprimir_Arvore_Rb(H->Tab[i],2);
        printf("\n");
    }

}
void imprimir_Tab_PosOrdem(HRNTree* H){
    for (int i =0; i< H->size; i++){
        printf("Imprimindo a Posiçao %d da Tabela\n",i);
        imprimir_Arvore_Rb(H->Tab[i],3);
        printf("\n");
    }

}
void liberar_Tab(HRNTree* H){
    for (int i = 0; i < H->size; i++){
        liberar_arvore_Rb(H->Tab[i]);
        free(H->Tab[i]);
    }
}
