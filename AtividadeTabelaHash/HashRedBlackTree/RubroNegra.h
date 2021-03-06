//
// Created by WizIbk on 08/05/18.
//

#ifndef ARVORERUBRONEGRA_RUBRONEGRA_H
#define ARVORERUBRONEGRA_RUBRONEGRA_H

enum { BLACK = 0, RED = 1} Color;
typedef struct No {
    int Chave;
    int Cor ;
    struct No* pai;
    struct No* esq;
    struct No* dir;
}Nodo;



typedef struct arv {
   Nodo* raiz;
   Nodo Sentinela;
}ArvRbrNeg;

ArvRbrNeg* criar_arvore();
Nodo* criar_nodo(int valor);
//ArvRbrNeg* Rb_inserir_arvore(ArvRbrNeg* Arv,Nodo* inserido);
Nodo* Rb_inserir_nodo(ArvRbrNeg* Arv, Nodo* inserido);
void Rb_fix_up_insert(ArvRbrNeg* Arv, Nodo* inserido);
int  verificar_filho(Nodo* raiz);
//ArvRbrNeg* Rb_remover_arvore(ArvRbrNeg* Arv , Nodo* removido );
Nodo* Rb_remover_nodo(ArvRbrNeg* raiz , Nodo * removido);
void Rb_fix_up_remove(ArvRbrNeg *Arv, Nodo *elemento);
//void buscar_arvore(ArvRbrNeg* Arv, int valor);
Nodo* buscar_nodo(Nodo* raiz,int valor);
void left_rotate(ArvRbrNeg* Arv,Nodo * x);
void right_rotate(ArvRbrNeg*Arv, Nodo * x);
void liberar_arvore_Rb(ArvRbrNeg* Arv);
void liberar_nodo(Nodo* raiz);
void imprimir_Arvore_Rb(ArvRbrNeg *Arv, int escolha);
void imprimir_PreOrdem(Nodo* raiz);
void imprimir_EmOrdem(Nodo* raiz);
void imprimir_PosOrdem(Nodo* raiz);

#endif //ARVORERUBRONEGRA_RUBRONEGRA_H
