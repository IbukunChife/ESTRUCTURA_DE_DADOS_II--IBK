//
// Created by WizIbk on 09/05/18.
//

#include <stdio.h>
#include <stdlib.h>
#include "RubroNegra.h"

ArvRbrNeg* criar_arvore(){
    ArvRbrNeg* novo = (ArvRbrNeg*)malloc(sizeof(ArvRbrNeg));
    novo->raiz=NULL;
}
Nodo* criar_nodo(int valor){
    Nodo * novo = (Nodo*)malloc(sizeof(Nodo));
    novo->esq=novo->dir=novo->pai=NULL;
    novo->Cor = RED;
    return novo;
}

void left_rotate(ArvRbrNeg* Arv,Nodo * x){
    Nodo* y = x->dir;
    x->dir = y->esq;
    if(y->esq != NULL){
        y->esq->pai=x;
    }
    y->pai = x->pai;
    if(x->pai == NULL){
        Arv->raiz=y;
    }else if (x->pai->esq == x){
        x->pai->esq = y;
    }else
        x->pai->dir = y;
    y->esq = x;
    x->pai = y;
}
void right_rotate(ArvRbrNeg*Arv, Nodo * x){
    Nodo* y = x->esq;
    x->esq = y->dir;
    if(y->dir != NULL){
        y->dir->pai=x;
    }
    y->pai = x->pai;
    if(x->pai == NULL){
        Arv->raiz=y;
    }else if (x->pai->esq == x){
        x->pai->esq = y;
    }else
        x->pai->dir = y;
    y->dir = x;
    x->pai = y;
}
void Rb_inserir_arvore(ArvRbrNeg* Arv,Nodo* inserido){
     Rb_inserir_nodo(Arv,inserido);
}
void Rb_inserir_nodo(ArvRbrNeg* Arv, Nodo* inserido){
    Nodo* y = NULL;
    Nodo* x = Arv->raiz;
    while(x!=NULL){
        y=x;
        if(inserido->Chave < x->Chave){
            x = x->esq;
        }else
            x= x->dir;
    }
    inserido->pai=y;
    if(y==NULL)
        Arv->raiz=inserido;
    else if(inserido->Chave < y->Chave)
        y->esq=inserido;
    else
        y->dir=inserido;
    Rb_fix_up_insert(Arv,inserido);
}

void Rb_fix_up_insert(ArvRbrNeg* Arv, Nodo* inserido){
    while (inserido->pai->Cor == RED){
        if(inserido->pai->pai->esq == inserido->pai){
                Nodo* y = inserido->pai->pai->dir;
                if (y->Cor==RED){ ///CASO 1
                    inserido->pai->Cor= BLACK;
                    y->Cor = BLACK;
                    inserido->pai->pai->Cor = RED;
                    inserido = inserido->pai->pai;
                }else{

                    if(inserido==inserido->pai->dir){///CASO 2
                        inserido = inserido->pai;
                        left_rotate(Arv,inserido);
                    }
                    inserido->pai->Cor = BLACK;///CASO 3
                    inserido->pai->pai->Cor = RED;
                    right_rotate(Arv,inserido->pai->pai);
                }
        }else{
            Nodo* y = inserido->pai->pai->esq;
            if (y->Cor==RED){ ///CASO 1
                inserido->pai->Cor= BLACK;
                y->Cor = BLACK;
                inserido->pai->pai->Cor = RED;
                inserido = inserido->pai->pai;
            }else{

                if(inserido==inserido->pai->esq){///CASO 2
                    inserido = inserido->pai;
                    right_rotate(Arv,inserido);
                }
                inserido->pai->Cor = BLACK;///CASO 3
                inserido->pai->pai->Cor = RED;
                left_rotate(Arv,inserido->pai->pai);
            }

        }
    }
    Arv->raiz->Cor=BLACK;
}

void Rb_remover_arvore(ArvRbrNeg* Arv , int valor){

}
Nodo* Rb_remover_nodo(Nodo* raiz , int valor){

}
void buscar_arvore(ArvRbrNeg* Arv, int valor){

}
Nodo* buscar_nodo(Nodo* raiz,int valor){

}

void liberar_arvore_Rb(ArvRbrNeg* Arv){
    liberar_nodo(Arv->raiz);
    free(Arv);
}
void liberar_nodo(Nodo* raiz){
    while(raiz!=NULL){
        liberar_nodo(raiz->esq);
        liberar_nodo(raiz->dir);
        free(raiz);
    }
}

void imprimir_Arvore_Rb(ArvRbrNeg* Arv,int  escolha){
    if(escolha == 1){
        imprimir_PreOrdem(Arv->raiz);
    }
    else if(escolha == 2){
        imprimir_EmOrdem(Arv->raiz);
    }
    else if(escolha == 3){
        imprimir_PosOrdem(Arv->raiz);
    }
    else
        printf("valor invalido somente [1-3]\n");
    printf("\n");

}
void imprimir_PreOrdem(Nodo* raiz){
    if(raiz != NULL){
        printf("%d\n", raiz->Chave);
        imprimir_PreOrdem(raiz->esq);
        imprimir_PreOrdem(raiz->dir);
    }

}
void imprimir_EmOrdem(Nodo* raiz){
    if(raiz != NULL){
        imprimir_EmOrdem(raiz->esq);
        printf("%d\n", raiz->Chave);
        imprimir_EmOrdem(raiz->dir);
    }

}
void imprimir_PosOrdem(Nodo* raiz){
    if(raiz != NULL){
        imprimir_PosOrdem(raiz->esq);
        imprimir_PosOrdem(raiz->dir);
        printf("%d\n", raiz->Chave);
    }

}





