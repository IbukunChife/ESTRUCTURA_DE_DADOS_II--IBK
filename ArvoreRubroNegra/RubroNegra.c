//
// Created by WizIbk on 09/05/18.
//

#include <stdio.h>
#include <stdlib.h>
#include "RubroNegra.h"

ArvRbrNeg *criar_arvore() {
    ArvRbrNeg *novo = (ArvRbrNeg *) malloc(sizeof(ArvRbrNeg));
    novo->raiz = NULL;
    return novo;
}

Nodo *criar_nodo(int valor) {
    Nodo *novo = (Nodo *) malloc(sizeof(Nodo));
    novo->Chave = valor;
    novo->esq = novo->dir = novo->pai = NULL;
    novo->Cor = RED;
    return novo;
}

void left_rotate(ArvRbrNeg *Arv, Nodo *x) {
    Nodo *y = x->dir;
    x->dir = y->esq;
    if (y->esq != NULL) {
        y->esq->pai = x;
    }
    y->pai = x->pai;
    if (x->pai == NULL) {
        Arv->raiz = y;
    } else if (x->pai->esq == x) {
        x->pai->esq = y;
    } else
        x->pai->dir = y;
    y->esq = x;
    x->pai = y;
}

void right_rotate(ArvRbrNeg *Arv, Nodo *x) {
    Nodo *y = x->esq;
    x->esq = y->dir;
    if (y->dir != NULL) {
        y->dir->pai = x;
    }
    y->pai = x->pai;
    if (x->pai == NULL) {
        Arv->raiz = y;
    } else if (x->pai->dir == x) {
        x->pai->dir = y;
    } else
        x->pai->esq = y;
    y->dir = x;
    x->pai = y;
}


Nodo *buscar_nodo(Nodo *raiz, int valor) {
    if (raiz == NULL || raiz->Chave == valor) {
        return raiz;
    } else if (valor < raiz->Chave) {
        return buscar_nodo(raiz->esq, valor);
    } else {
        return buscar_nodo(raiz->dir, valor);
    }
}

Nodo *Rb_inserir_nodo(ArvRbrNeg *Arv, Nodo *inserido) {
    Nodo *y = NULL;
    Nodo *x = Arv->raiz;
    while (x != NULL) {
        y = x;
        if (inserido->Chave < x->Chave) {
            x = x->esq;
        } else
            x = x->dir;
    }
    inserido->pai = y;
    if (y == NULL) {
        Arv->raiz = inserido;
    } else if (inserido->Chave < y->Chave) {
        y->esq = inserido;
    } else {
        y->dir = inserido;
    }
    Rb_fix_up_insert(Arv, inserido);
    return Arv->raiz;
}

void Rb_fix_up_insert(ArvRbrNeg *Arv, Nodo *inserido) {
    while (inserido != Arv->raiz && inserido->pai->Cor == RED) {
        if (inserido->pai->pai->esq == inserido->pai) {
            Nodo *y = inserido->pai->pai->dir;
            if (y != NULL && y->Cor == RED) { ///CASO 1
                inserido->pai->Cor = BLACK;
                y->Cor = BLACK;
                inserido->pai->pai->Cor = RED;
                inserido = inserido->pai->pai;
            } else {
                if (inserido == inserido->pai->dir) {///CASO 2
                    inserido = inserido->pai;
                    left_rotate(Arv, inserido);
                }
                inserido->pai->Cor = BLACK;///CASO 3
                inserido->pai->pai->Cor = RED;
                right_rotate(Arv, inserido->pai->pai);
            }

        } else {

            Nodo *y = inserido->pai->pai->esq;
            if (y != NULL && y->Cor == RED) { ///CASO 1
                inserido->pai->Cor = BLACK;
                y->Cor = BLACK;
                inserido->pai->pai->Cor = RED;
                inserido = inserido->pai->pai;
            } else {
                if (inserido == inserido->pai->esq) {///CASO 2
                    inserido = inserido->pai;
                    right_rotate(Arv, inserido);
                }
                inserido->pai->Cor = BLACK;///CASO 3
                inserido->pai->pai->Cor = RED;
                left_rotate(Arv, inserido->pai->pai);
            }
        }
    }
    Arv->raiz->Cor = BLACK;
}

int verificar_filho(Nodo *raiz) {
    if (raiz->esq != NULL && raiz->dir == NULL) {
        return 1;
    }
    if (raiz->esq == NULL && raiz->dir != NULL) {
        return 1;
    }
    if (raiz->esq == NULL && raiz->dir == NULL) {
        return 0;
    }
    if (raiz->esq != NULL && raiz->dir != NULL) {
        return 2;
    }
}

/*
ArvRbrNeg* Rb_remover_arvore(ArvRbrNeg *Arv, Nodo *removido) {
    Arv->raiz=Rb_remover_nodo(Arv, removido);
}
*/
Nodo *Rb_remover_nodo(ArvRbrNeg *Arv, Nodo *removido) {
    while (removido != NULL) {
        Nodo *y = removido->pai;
        Nodo *x = removido;
        int n = verificar_filho(x);
        if (n == 0) {
            if (y->esq == x)
                y->esq = NULL;
            else
                y->dir = NULL;
            free(x);
           Rb_fix_up_remove(Arv, y);
        }
        if (n == 1) {
            if (x->esq) {
                Nodo *aus = x;
                x = x->esq;
                free(aus);
            } else {
                Nodo *aus = x;
                x = x->dir;
                free(aus);
            }
          //  Rb_fix_up_remove(Arv, y);
        }
        if (n == 2) {
            Nodo *p = x->esq;
            while (p->dir != NULL) {
                p = p->dir;
            }
            x->Chave = p->Chave;
            p->Chave = removido->Chave;
            removido = p;
            y = removido->pai;
        }

    }
    return Arv->raiz;
}

void Rb_fix_up_remove(ArvRbrNeg *Arv, Nodo *elemento) {
    //  while (elemento != Arv->raiz) {}
    if (elemento->pai->esq == elemento) {
        Nodo *Pai = elemento->pai;
        Nodo *Irmao = elemento->pai->dir;
        if (Irmao->Cor == RED) { /// CASO 1
            Irmao->Cor = BLACK;
            Pai->Cor = RED;
            left_rotate(Arv, Irmao);
        }
        if (Irmao->Cor == BLACK && Pai->Cor == BLACK) { /// CASO 2.1
            Irmao->Cor = RED;
            elemento = Pai;
            Rb_fix_up_remove(Arv, elemento);
        }
        if (Irmao->Cor == BLACK && Pai->Cor == RED && Irmao->esq->Cor ==BLACK && Irmao->dir->Cor == BLACK) { /// CASO 2.2
            Irmao->Cor = RED;
            Pai->Cor = BLACK;
        }
        if (Irmao->Cor == BLACK && Irmao->esq->Cor == RED && Irmao->dir->Cor == BLACK) { /// CASO 3
            Irmao->esq->Cor = BLACK;
            Irmao->Cor = RED;
            right_rotate(Arv, Irmao);
            Rb_fix_up_remove(Arv, elemento);
        }
        if (Irmao->Cor == BLACK && Irmao->dir->Cor == RED) { /// CASO 4
            Irmao->Cor = Pai->Cor;
            Pai->Cor = BLACK;
            Irmao->dir = BLACK;
            left_rotate(Arv, Irmao);
        }

    } else {

        Nodo *Pai = elemento->pai;
        Nodo *Irmao = elemento->pai->esq;
        if (Irmao->Cor == RED) { /// CASO 1
            Irmao->Cor = BLACK;
            Pai->Cor = RED;
            right_rotate(Arv, Irmao);
        }
        if (Irmao->Cor == BLACK && Pai->Cor == BLACK) { /// CASO 2.1
            Irmao->Cor = RED;
            elemento = Pai;
            Rb_fix_up_remove(Arv, elemento);
        }
        if (Irmao->Cor == BLACK && Pai->Cor == RED && Irmao->dir->Cor == Irmao->esq->Cor == BLACK) { /// CASO 2.2
            Irmao->Cor = RED;
            Pai->Cor = BLACK;
        }
        if (Irmao->Cor == BLACK && Irmao->dir->Cor == RED && Irmao->esq->Cor == BLACK) { /// CASO 3
            Irmao->dir->Cor = BLACK;
            Irmao->Cor = RED;
            right_rotate(Arv, Irmao);
            Rb_fix_up_remove(Arv, elemento);
        }
        if (Irmao->Cor == BLACK && Irmao->esq->Cor == RED) { /// CASO 4
            Irmao->Cor = Pai->Cor;
            Pai->Cor = BLACK;
            Irmao->esq = BLACK;
            left_rotate(Arv, Irmao);
        }
    }

}


void liberar_arvore_Rb(ArvRbrNeg *Arv) {
    liberar_nodo(Arv->raiz);
    free(Arv);
}

void liberar_nodo(Nodo *raiz) {
    while (raiz != NULL) {
        liberar_nodo(raiz->esq);
        liberar_nodo(raiz->dir);
        free(raiz);
    }
}

void imprimir_Arvore_Rb(ArvRbrNeg *Arv, int escolha) {
    if (escolha == 1) {
        imprimir_PreOrdem(Arv->raiz);
    } else if (escolha == 2) {
        imprimir_EmOrdem(Arv->raiz);
    } else if (escolha == 3) {
        imprimir_PosOrdem(Arv->raiz);
    } else
        printf("valor invalido somente [1-3]\n");
    printf("\n");

}

void imprimir_PreOrdem(Nodo *raiz) {
    if (raiz != NULL) {
        printf("%d\n", raiz->Chave);
        imprimir_PreOrdem(raiz->esq);
        imprimir_PreOrdem(raiz->dir);
    }

}

void imprimir_EmOrdem(Nodo *raiz) {
    if (raiz != NULL) {
        imprimir_EmOrdem(raiz->esq);
        printf("%d\n", raiz->Chave);
        imprimir_EmOrdem(raiz->dir);
    }

}

void imprimir_PosOrdem(Nodo *raiz) {
    if (raiz != NULL) {
        imprimir_PosOrdem(raiz->esq);
        imprimir_PosOrdem(raiz->dir);
        printf("%d\n", raiz->Chave);
    }

}





