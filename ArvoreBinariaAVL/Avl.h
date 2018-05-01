//
// Created by WizIbk on 26/04/18.
//

#ifndef ARVOREBINARIAAVL_AVL_H
#define ARVOREBINARIAAVL_AVL_H
typedef struct no {
    int info;
    int alt;
    struct no* esq;
    struct no* dir;
}Nodo;

typedef struct arv{
    Nodo* raiz;
} ArvBinAvl;

ArvBinAvl * criar_arv();
ArvBinAvl* arv_cria_raiz(Nodo* raiz);
Nodo* criar_Nodo(int info, Nodo * esq, Nodo *dir);
Nodo* inserir_Nodo(Nodo*r, int chave);
Nodo* remover(Nodo*raiz, int chave);
void inserir_arv(ArvBinAvl* arv, int chave);
void remover_arv(ArvBinAvl*arv, int chave);
void imprimir_arv(ArvBinAvl* arv, int escolha);
void imprimir_PreOrdem(Nodo* raiz);
void imprimir_EmOrdem(Nodo* raiz);
void imprimir_PosOrdem(Nodo* raiz);
void imprimir_Arv_formatado(ArvBinAvl* arv);
void imprimir_Avr_formatado_no(Nodo * raiz);
void libera(ArvBinAvl* a);
void libera_no(Nodo * raiz);
int max(int A, int B);
int arv_pertence(ArvBinAvl* a, int c);
int arv_pertence_no(Nodo* a, int c);
int alt_no(Nodo* raiz);
int altura(Nodo* raiz);
int arv_altura(ArvBinAvl *raiz);

#endif //ARVOREBINARIAAVL_AVL_H
