//
// Created by WizIbk on 27/05/18.
//

#ifndef ARVOREB_ARV_H
#define ARVOREB_ARV_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum {
    left = -1, right = 1
} position_t;

typedef struct nodo {
    int num;
    int nivel;
    bool folha;
    int *chaves;
    struct nodo **filhos;
    struct  nodo * next;
} Pagina;

typedef struct ArvB {
    unsigned int ORDEM;
    Pagina *raiz;
    unsigned int MIN_OCUP;
} Btree;

typedef struct {
    Pagina *nodo;
    int index;
} Pag_pos;

Btree *Criar_ArvoreB(unsigned int ordem);

static Pagina *Criar_Pagina(unsigned int ordem);

static void Split_filhos(Btree *btree, Pagina *Pai, int index, Pagina *filhos);

static void Insert_naoCheia(Btree *btree, Pagina *Pai, int val);

int Insert_Chave(Btree *btree, int key);

/// MERGE NODO N1 E N2 (CASO 3b DE Cormen)
static Pagina *merge_irmao(Btree *btree, Pagina *Pai, unsigned int index, position_t pos);

static Pagina *merge_Pagina(Btree *btree, Pagina *n1, int val, Pagina *n2);

static void mover_Chave(Btree *btree, Pagina *node, unsigned int index, position_t pos);

int remove_Chave_dentro_Pagina(Btree *btree, Pag_pos *node_pos);

int remover_Chave_NaArvore(Btree *btree, Pagina *subtree, int val);

static Pag_pos Obter_pos_chave_max(Btree *btree, Pagina *subtree);

static Pag_pos Obter_pos_chave_min(Btree *btree, Pagina *subtree);

Pag_pos busca_chave(Btree *btree, int val);
void imprimir_Pagina(Btree *btree, Pagina * node);
void Imprimir_SubArvore(Btree *btree,Pagina * node);
static int Liberar_Pagina(Pagina *no);
void liberar_ArvoreB(Btree * btree);


#endif //ARVOREB_ARV_H
