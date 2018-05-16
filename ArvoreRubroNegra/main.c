#include <stdio.h>
#include <stdlib.h>
#include "RubroNegra.h"

int main() {
    ArvRbrNeg * arvore = criar_arvore();
   // 23,21,4,43,78,32,12,9
    arvore->raiz =Rb_inserir_nodo(arvore,criar_nodo(23));
    arvore->raiz =Rb_inserir_nodo(arvore,criar_nodo(21));
    arvore->raiz =Rb_inserir_nodo(arvore,criar_nodo(4));
    arvore->raiz =Rb_inserir_nodo(arvore,criar_nodo(43));
    arvore->raiz =Rb_inserir_nodo(arvore,criar_nodo(78));
    arvore->raiz =Rb_inserir_nodo(arvore,criar_nodo(32));
    arvore->raiz =Rb_inserir_nodo(arvore,criar_nodo(12));
    arvore->raiz =Rb_inserir_nodo(arvore,criar_nodo(9));
   // arvore->raiz =Rb_inserir_nodo(arvore,criar_nodo(15));

    imprimir_Arvore_Rb(arvore,2);
    arvore->raiz =Rb_remover_nodo(arvore,buscar_nodo(arvore->raiz,43));
    arvore->raiz =Rb_remover_nodo(arvore,buscar_nodo(arvore->raiz,78));

    printf("\n\n");
    imprimir_Arvore_Rb(arvore,2);

    //liberar_arvore_Rb(arvore);
    return 0;
}