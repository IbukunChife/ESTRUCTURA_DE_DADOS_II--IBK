//
// Created by WizIbk on 18/06/18.
//

#ifndef HASHREDBLACKTREE_HRNTREE_H
#define HASHREDBLACKTREE_HRNTREE_H

#include "RubroNegra.h"

typedef struct hash{
    ArvRbrNeg **Tab;
    int size;
}HRNTree;

HRNTree* criar_tab(int n);
void inserir_No_Tab(HRNTree * H, int chave);
void remover_No_Tab(HRNTree* H, int chave);
void imprimir_Tab(HRNTree* H);
void imprimir_Tab_PreOrdem(HRNTree* H);
void imprimir_Tab_EmOrdem(HRNTree* H);
void imprimir_Tab_PosOrdem(HRNTree* H);
void liberar_Tab(HRNTree* H);






#endif //HASHREDBLACKTREE_HRDTREE_H
