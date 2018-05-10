
//Prefixa, Infixa e Posfixa

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    char valor;
    struct no * esq;
    struct no * dir;
}Nodo;

typedef struct arvore{
    Nodo* principal;
}ArvBin;

ArvBin* criar_arvore(){
    ArvBin* Pai = (ArvBin*)malloc(sizeof (ArvBin));
    return Pai;
}

Nodo* criar_no( char info){
    Nodo* novo = (Nodo *)malloc (sizeof (Nodo));
    novo->valor = info;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

void libera_no(Nodo* raiz){
    if(raiz != NULL){
        libera_no(raiz->esq);
        libera_no(raiz->dir);
        free(raiz);
    }
}

void libera_arv(ArvBin* arv){
    libera_no(arv->principal);
    free(arv);
}


int Buscar_index(char * IN,int ini, int fim ,char letra){
    for (int i = ini ;i<=fim;i++){
        if (IN[i]==letra){
            return  i;
        }
    }
    // return -1;
}

static int in_pre =0 ;

Nodo* construir_arvore (char* Pre, char* In, int ini, int fim ){

    int indiceRaiz;
    Nodo* raiz;
    if (ini>fim){
        return NULL;
    }
    if (ini==fim){
        raiz = criar_no (Pre[in_pre++]);
        return raiz;
    }
    if(ini<fim){
        raiz = criar_no (Pre[in_pre]);
        indiceRaiz = Buscar_index (In, ini, fim,Pre[in_pre++]);
        raiz->esq = construir_arvore (Pre,In,ini,indiceRaiz-1);
        raiz->dir = construir_arvore (Pre,In,indiceRaiz+1,fim);
        return raiz;
    }

}

void imprimir_Pos_ordem(Nodo * arv){
    if(arv !=NULL){
        imprimir_Pos_ordem (arv->esq);
        imprimir_Pos_ordem (arv->dir);
        printf ("%c",arv->valor);
    }
}

void imprimir_arvore(ArvBin * arv){
    imprimir_Pos_ordem (arv->principal);
}

int main() {
    char prefixe [53];
    char infixe [53];
    int len;
    int teste;
    int num_de_no;
    scanf ("%d",&teste);
    setbuf (stdin,NULL);
    if (teste <=2000){
        for(int i =0;i<teste;i++){
            scanf ("%d",&num_de_no);
            if(num_de_no>=1 && num_de_no<=52){
                setbuf (stdin,NULL);
                scanf( "%s %s",prefixe,infixe);
                setbuf (stdin,NULL);
                ArvBin* arv = criar_arvore ();
                len = (int) strlen (prefixe);
                if (strlen (prefixe) == strlen (infixe)){
                    arv->principal = construir_arvore (prefixe,infixe,0,len-1);
                    imprimir_arvore(arv);
                    printf("\n");
                }
                libera_arv (arv);
                in_pre =0;
            }


        }
    }

    return 0;
}
