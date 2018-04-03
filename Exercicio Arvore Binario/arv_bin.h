#ifndef __ARV_BIN_H__
#define __ARV_BIN_H__

typedef struct no {
    char info;
    struct no* esq;
    struct no* dir;
}Nodo;

typedef struct arv{
    Nodo* raiz;
}ArvBin;

ArvBin* arv_cria(Nodo * raiz);
Nodo* arv_cria_no(char informacao, Nodo* esq, Nodo* dir);

void imprime_escolhendo_ordem(ArvBin* arvore, int ordem);
void imprime_pre_ordem(Nodo* raiz );
void imprime_in_ordem(Nodo * raiz);
void imprime_pos_ordem(Nodo *raiz);

void imprimir_formato_arv(ArvBin* arvore);
void imprimir_formato_no(Nodo* raiz);

int arv_pertence(ArvBin *arvore,char informacao);
int arv_pertence_no(Nodo * raiz , char informacao);

Nodo* arv_busca(ArvBin * arvore,char informacao);
Nodo* arv_busca_no(Nodo * raiz, char informacao );

int arv_altura(ArvBin* arvore);
int arv_altura_no(Nodo* raiz);

void arv_libera(ArvBin* arv);
void arv_libera_no(Nodo* raiz);


#endif

