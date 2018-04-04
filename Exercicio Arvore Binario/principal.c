#include <stdio.h>
#include <stdlib.h>
#include "arv_bin.h"
#include "funcao.h"

int main (){

    // Criando a Arvore

    ArvBin* Pai = arv_cria(
            arv_cria_no('a',
                           arv_cria_no('b',arv_cria_no('d',NULL,NULL),
                                         arv_cria_no('e',NULL,arv_cria_no('h',NULL,NULL))),
                           arv_cria_no('c',arv_cria_no('f',arv_cria_no('i',arv_cria_no('j',NULL,NULL),NULL),NULL),
                                         arv_cria_no('g',NULL,NULL)))
    );

    printf("\n\n Imprimindo em pré_ordem \n\n");
    imprime_escolhendo_ordem(Pai,1);
    printf("\n\n Imprimindo em ordem \n\n");
    imprime_escolhendo_ordem(Pai,2);
    printf("\n\n Imprimindo em pos_ordem \n\n");
    imprime_escolhendo_ordem(Pai,3);

    printf("\n\n Verificando se << e >> pertence a arvore \n");
    arv_pertence(Pai,'e') ? printf("Sim\n") : printf("não\n");

    printf("\n Buscando <<f>> na Arvore \n");
    Nodo *procurado = arv_busca(Pai,'f');
    if (procurado != NULL)
        printf("Nodo Encontrado: %c \n", procurado->info);

    printf("\nImprimindo a Arvore:\n");
    imprimir_formato_arv(Pai);

    printf("Altura da arvore: %d\n", arv_altura(Pai));

    printf ("\nImprimir em LARGURA a Arvore:\n");
    imprimir_em_largura_arvore (Pai);

    printf ("\nO Tamanho da Arvore é: %d \n",tamanho_arvore (Pai));

    ArvBin * espelho = arv_cria (arv_cria_no (' ',NULL,NULL));
    espelho_arvore (Pai, espelho);
    printf ("\n A arvore ESPELHO é :\n");
    imprimir_formato_arv(espelho);

    printf ("\nImprimir em LARGURA a Arvore ESPELHO:\n");
    imprimir_em_largura_arvore (espelho);


    printf ("\n IMPRIMINDO COM AS FERRAMENTAS NAO_RECURSIVA\n");

    printf("\n\n Imprimindo em pré_ordem_NAO_RECURSIVO_O_ESPELHO\n\n");
    imprime_escolhendo_ordemNaoRecursivo(Pai,1);
    printf("\n\n Imprimindo em ordem_NAO_RECURSIVO_O_ESPELHO \n\n");
    imprime_escolhendo_ordemNaoRecursivo(Pai,2);
    printf("\n\n Imprimindo em pos_ordem_NAO_RECURSIVO_O_ESPELHO \n\n");
    imprime_escolhendo_ordemNaoRecursivo(espelho,3);


    printf ("\n\n Imprimindo o NUMERO DE FOLHA DE UMA ARVORE \n\n");
    printf ("O numero de Folha da Arvore é: %d \n" , Numero_De_Folha_Arvore (Pai));

    printf ("\n\n Verificando se A ARVORE É ESTREITAMENTE BINARIA \n\n");
    if ( Verificar_Arvore_Estreitamente_binaria (Pai)) {
        printf ("\n ARVORE É ESTREITAMENTE BINARIA \n");
    } else {
        printf ("\n ARVORE não É ESTREITAMENTE BINARIA \n");
    }

    printf ("\n\n Verificando se A ARVORE É COMPLETA \n\n");
    if ( Verificar_Arvore_completa (Pai)) {
        printf ("\n ARVORE É COMPLETA \n");
    } else {
        printf ("\n ARVORE não É COMPLETA \n");
    }



   arv_libera(Pai);
   arv_libera (espelho);
   return 0;
}