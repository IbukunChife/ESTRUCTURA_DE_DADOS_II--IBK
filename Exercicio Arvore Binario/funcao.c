//
// Created by IBK on 25/03/18.
//
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "arv_bin.h"
#include "funcao.h"
#include "pila.h"

void imprimir_em_largura_arvore(ArvBin* arv){
    imprimir_em_largura_no (arv->raiz);
}

void imprimir_em_largura_no(Nodo* no ){
    Fila * f = criar_fila();
    inserir_fila(f,no);
        while (!fila_vazia(f)){
            Nodo* p = retirar_fila(f);
            if (p!=NULL){
                printf("%c ", p->info);
                inserir_fila(f,p->esq);
                inserir_fila(f,p->dir);
            }
        }
    liberar_fila(f);
}

int tamanho_arvore(ArvBin* arv){
    return numero_de_no(arv->raiz);
}

int numero_de_no(Nodo* no){

    Nodo * raiz = no;
    int contador = 0;
    if (raiz != NULL){
        contador = 1 + numero_de_no (raiz->esq);
        contador += numero_de_no (raiz->dir);
    }
    return contador;

}

void espelho_arvore(ArvBin* original , ArvBin* esp_copia ){
    espelho_no(original->raiz,esp_copia->raiz);
}

void espelho_no(Nodo* original, Nodo* espelho){
    espelho->info = original->info;
    if (original->dir != NULL) {
        Nodo *novo = arv_cria_no (' ' , NULL , NULL);
        espelho->esq = novo;
        espelho_no (original->dir , espelho->esq);
    }
    if (original->esq != NULL) {
        Nodo *novo = arv_cria_no (' ' , NULL , NULL);
        espelho->dir = novo;
        espelho_no (original->esq , espelho->dir);
    }

}

void imprime_escolhendo_ordemNaoRecursivo(ArvBin* arvore, int ordem){
    if (ordem ==1){
        imprimir_Pre_OrdemNaoRecursivo (arvore->raiz);
    }else if (ordem == 2){
        imprimir_Em_OrdemNaoRecursivo (arvore->raiz);
    }else if (ordem == 3){
        imprimir_Pos_OrdemNaoRecursivo (arvore->raiz);
    }else {
        printf("Valor Invalido. Digite um valor entre [1-3].\n");
    }

}
void imprimir_Pre_OrdemNaoRecursivo(Nodo* raiz ){
    if (!raiz) return;
    Pila * pi = criar_pila ();// esta é uma pilha de Ponteiros
    push(pi, raiz);
    Nodo* atual;
    while (!pila_vazia (pi)) {
        atual = pop(pi);
        printf("%c ",atual->info);
        if (atual->dir!=NULL) push( pi,atual->dir);
        if (atual->esq!=NULL) push( pi,atual->esq);
    }
    printf("\n");
}


void imprimir_Em_OrdemNaoRecursivo(Nodo* raiz ){
    if (!raiz) return;
    Nodo* p = raiz;
    Pila* pi  = criar_pila();
    while (p != NULL) {
        while(p != NULL) {
            if (p->dir != NULL)
                push(pi,p->dir);// empilhar filho da direita (se houver)
            push(pi,p);// e o próprio nó quando for
            p = p->esq;// para a esquerda;
        }
        p = pop(pi);   // pop em nó sem filho esquerdo
        while (!pila_vazia (pi) && p->dir == NULL) {
            printf("%c ",p->info); // visita-lo e a todos os nós
            p = pop(pi);// sem filho direito;
        }
        printf("%c ",p->info);                   // visitar também o primeiro nó com
        if (!pila_vazia (pi))
            p = pop(pi);// um filho direito (se houver);
        else p = NULL;
    }

}
void imprimir_Pos_OrdemNaoRecursivo(Nodo* raiz ){
    if (!raiz) return;
    Pila * pi = criar_pila ();// esta é uma pilha de Ponteiros
    Nodo* p = raiz;
    Nodo* q = raiz;
        while (p != NULL) {
            /* for ( ; p->esq != NULL; p = p->esq)
                 push(pi,p);*/
            while (p->dir != NULL) {
                push (pi , p);
                p = p->dir;
            }
            while (p != NULL && (p->esq == NULL ||
                                 p->esq == q)) {
                printf("%c ",p->info);
                q = p;
                if (pila_vazia (pi))
                    return;
                p = pop(pi);
            }
            push(pi,p);
            p = p->esq;
        }
}

int Numero_De_Folha_Arvore(ArvBin *arvore) {
    return Numero_De_Folha_No (arvore->raiz);
}

int Numero_De_Folha_No(Nodo *raiz) {
    int contador = 0;
    if ( raiz != NULL) {
        if ( raiz->esq == NULL && raiz->dir == NULL) {
            return 1;
        }
        if ( raiz->esq != NULL && raiz->dir == NULL) {
            contador += Numero_De_Folha_No (raiz->esq);
        }
        if ( raiz->esq == NULL && raiz->dir != NULL) {
            contador += Numero_De_Folha_No (raiz->dir);
        }
        if ( raiz->esq != NULL && raiz->dir != NULL) {
            contador += Numero_De_Folha_No (raiz->esq);
            contador += Numero_De_Folha_No (raiz->dir);
        }
        return contador;
    }

}

bool Verificar_Arvore_Estreitamente_binaria(ArvBin *arvore) {
    return Verificar_No_Estreitamente_binaria (arvore->raiz);
}

bool Verificar_No_Estreitamente_binaria(Nodo *raiz) {
    int contador = 0;
    if ( raiz != NULL) {
        if ( raiz->esq == NULL && raiz->dir == NULL) {
            contador += 0;
        }
        if ( raiz->esq != NULL && raiz->dir == NULL) {
            contador += 1;
        }
        if ( raiz->esq == NULL && raiz->dir != NULL) {
            contador += 1;
        }
        if ( raiz->esq != NULL && raiz->dir != NULL) {
            contador += 0;

        }
        contador += Numero_De_Folha_No (raiz->esq);
        contador += Numero_De_Folha_No (raiz->dir);
        return contador == 0 ? true : false;
    }

}

bool Verificar_Arvore_completa(ArvBin *arvore) {
    return Verificar_No_completa (arvore->raiz);
}

bool Verificar_No_completa(Nodo *raiz) {
    if ( raiz == NULL) {
        return -1;
    }
    int altura_esq = 1 + arv_altura_no (raiz->esq);
    int altura_dir = 1 + arv_altura_no (raiz->dir);

    return altura_esq == altura_dir ? true : false;

}
