#include <stdio.h>
#include <stdlib.h>
#include "arv_bin.h"


ArvBin* arv_cria(Nodo * raiz){
    ArvBin * arvore =(ArvBin*)malloc(sizeof(ArvBin));
    arvore->raiz = raiz;
    return arvore;
}

Nodo* arv_cria_no(char informacao, Nodo* esq, Nodo* dir){
    Nodo* novo = (Nodo *)malloc(sizeof(Nodo));
    novo->info = informacao;
    novo->esq = esq;
    novo->dir = dir;
    return  novo;
}


void imprime_escolhendo_ordem(ArvBin* arvore, int ordem){
    if (ordem ==1){
        imprime_pre_ordem(arvore->raiz);
    }else if (ordem == 2){
        imprime_in_ordem(arvore->raiz);
    }else if (ordem == 3){
        imprime_pos_ordem(arvore->raiz);
    }else {
        printf("Valor Invalido. Digite um valor entre [1-3].\n");
    }
}

void imprime_pre_ordem(Nodo* raiz ){
    if (raiz!=NULL){
        printf("%c ",raiz->info);
        imprime_pre_ordem(raiz->esq);
        imprime_pre_ordem(raiz->dir);
    }
}


void imprime_in_ordem(Nodo * raiz){
    if (raiz!=NULL){
        imprime_in_ordem(raiz->esq);
        printf("%c ",raiz->info);
        imprime_in_ordem(raiz->dir);
    }
}

void imprime_pos_ordem(Nodo* raiz){
    if (raiz!=NULL){
        imprime_pos_ordem(raiz->esq);
        imprime_pos_ordem(raiz->dir);
        printf("%c ",raiz->info);
    }
}

void imprimir_formato_arv(ArvBin* arvore){
    imprimir_formato_no(arvore->raiz);
    printf("\n");
}

void imprimir_formato_no(Nodo* raiz){
   // printf("<");
    if (raiz!=NULL){
        printf(" %c ",raiz->info);printf("(");
        imprimir_formato_no(raiz->esq);printf("|");
        imprimir_formato_no(raiz->dir);printf(")");
    }
   // printf(">");
}

int arv_pertence(ArvBin *arvore,char informacao){
    return arv_pertence_no(arvore->raiz, informacao);
}
int arv_pertence_no(Nodo * raiz , char informacao){
    if (raiz == NULL){
        return 0;
    }else if(raiz->info == informacao ){
        return 1;
    } else{
        return arv_pertence_no(raiz->esq,informacao)|| arv_pertence_no(raiz->dir,informacao);
    }

}


Nodo* arv_busca(ArvBin * arvore,char informacao){
    return arv_busca_no( arvore->raiz, informacao);
}

Nodo* arv_busca_no(Nodo * raiz, char informacao ){
    if (raiz == NULL){
        return NULL;
    }else if (raiz->info == informacao) {
            return raiz;
    }else {
        Nodo * no = arv_busca_no(raiz->esq, informacao);
        if (no!=NULL){
            return no;
        }else{
            return arv_busca_no(raiz->dir, informacao);
        }
    }

}


int arv_altura(ArvBin* arvore){
    return  arv_altura_no(arvore->raiz);
}
int arv_altura_no(Nodo* raiz){
    if(raiz == NULL){
        return -1;
    }
    int altura_esq = 1 + arv_altura_no(raiz->esq);
    int altura_dir = 1 + arv_altura_no(raiz->dir);

    return altura_esq > altura_dir ? altura_esq : altura_dir;
}


void arv_libera(ArvBin* arv){
    arv_libera_no(arv->raiz);
    free(arv);
}
void arv_libera_no(Nodo* raiz){
    if(raiz != NULL){
        arv_libera_no(raiz->esq);
        arv_libera_no(raiz->dir);
        free(raiz);
    }
}



