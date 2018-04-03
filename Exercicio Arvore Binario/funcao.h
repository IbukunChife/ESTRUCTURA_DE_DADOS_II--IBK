//
// Created by IBK on 28/03/18.
//

#ifndef EXERCICIO_ARVORE_BINARIO_FUNCAO_H
#define EXERCICIO_ARVORE_BINARIO_FUNCAO_H
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "arv_bin.h"

void imprimir_em_largura_arvore(ArvBin* arv);
void imprimir_em_largura_no(Nodo* no );
void imprime_escolhendo_ordemNaoRecursivo(ArvBin* arvore, int ordem);
void imprimir_Pre_OrdemNaoRecursivo(Nodo* raiz );
void imprimir_Em_OrdemNaoRecursivo(Nodo* raiz );
void imprimir_Pos_OrdemNaoRecursivo(Nodo* raiz );
int tamanho_arvore(ArvBin* arv);
int numero_de_no(Nodo* no);
void espelho_arvore(ArvBin* original , ArvBin* esp_copia );
void espelho_no(Nodo* original, Nodo* espelho);



#endif //EXERCICIO_ARVORE_BINARIO_FUNCAO_H
