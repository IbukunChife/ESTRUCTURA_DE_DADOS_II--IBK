
//O Hall dos Assassinos

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct assassinos{
    char nome[11];
    int crime;
    struct assassinos* prox;
}A;

typedef struct assassinados{
    char nome[11];
    struct assassinados* prox;
}B;

typedef struct list{
    A* lista_A;
    B* lista_B;
}Lista;

Lista * criar_lista(){
    Lista * novo = (Lista *)malloc (sizeof (Lista));
    novo->lista_A = NULL;
    novo->lista_B= NULL;
    return novo;
}

A* criar_assassino( char *a){
    A* novoA = (A*)malloc (sizeof (A));
    strcpy (novoA->nome,a);
    novoA->prox= NULL;
    novoA->crime =1;
    return novoA;
}

B* criar_assassinado( char *b){
    B* novoB = (B*)malloc (sizeof (B));
    strcpy (novoB->nome,b);
    novoB->prox= NULL;
    return novoB;
}
void inserir_listaA(Lista* L , char *a){
    if(L->lista_A == NULL){
        L->lista_A = criar_assassino (a);
    }else{
        A* aux;
        for (aux = L->lista_A; aux!=NULL;aux=aux->prox){
            if (strcmp (aux->nome,a)==0){
                (aux->crime)++;
                return;
            }
        }
        A* aus= L->lista_A;
        while(aus->prox!=NULL){
            aus = aus->prox;
        }
        aus->prox= criar_assassino (a);
    }

}

void inserir_listaB(Lista* L, char* b){
    if(L->lista_B == NULL){
        L->lista_B= criar_assassinado (b);
    }else{
        B* aux = L->lista_B;
        while(aux->prox!=NULL){
            aux = aux->prox;
        }
        aux->prox= criar_assassinado (b);
    }

}

void inserir_no(Lista* L , char* a, char* b){
   inserir_listaA (L,a);
   inserir_listaB (L,b);
}

void assassinatos(Lista* l){
    A* aux;
    B* aus;
    for (aux=l->lista_A; aux!=NULL; aux=aux->prox){
        for (  aus = l->lista_B ; aus !=NULL  ; aus=aus->prox ) {
            if (strcmp (aux->nome,aus->nome)==0){
                aux->crime = 0;
            }
        }

    }

}

void imprimir(Lista* l){
    printf ("HALL OF MURDERERS\n");
    for (A* aux=l->lista_A; aux!=NULL; aux=aux->prox){
        if(aux->crime!=0)
            printf ("%s %d\n",aux->nome,aux->crime);
    }
}

int main(){
    char assassino[11],assassinado[11];
    Lista * l = criar_lista ();
    while(scanf ("%s %s",assassino,assassinado)!=EOF){
        inserir_no (l,assassino,assassinado);
    }
    assassinatos (l);
    imprimir (l);
    return 0;
}
