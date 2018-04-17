#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int chave;
    struct no * esq;
    struct no * dir;
}Nodo;

typedef struct arv{
    Nodo* raiz;
}ArvBin;

ArvBin* criar_arv(){
    ArvBin* pai = (ArvBin *)malloc (sizeof (ArvBin));
    pai->raiz= NULL;
    return pai;
}

Nodo* criar_no(int valor){
    Nodo* novo = (Nodo*)malloc (sizeof (Nodo));
    novo->chave = valor;
    novo->esq= novo->dir= NULL;
    return novo;
}

static Nodo* inserir_no (Nodo* raiz, int valor){
    if(raiz==NULL){
        raiz = criar_no (valor);
    }else if( valor< raiz->chave){
        raiz->esq = inserir_no (raiz->esq,valor);
    }else if(valor > raiz->chave){
        raiz->dir = inserir_no (raiz->dir,valor);
    }
    return raiz;
}

void inserir_ArvBinBusca(ArvBin* arv, int valor){
    arv->raiz = inserir_no (arv->raiz,valor);
}

void imprimir_PreOrdem(Nodo* raiz){
    if (raiz!=NULL){
        printf (" %d",raiz->chave);
        imprimir_PreOrdem (raiz->esq);
        imprimir_PreOrdem (raiz->dir);
    }

}

void imprimir_EmOrdem(Nodo* raiz){
    if(raiz!=NULL){
        imprimir_EmOrdem (raiz->esq);
        printf (" %d",raiz->chave);
        imprimir_EmOrdem (raiz->dir);
    }

}

void imprimir_PosOrdem(Nodo* raiz){
    if (raiz!=NULL){
        imprimir_PosOrdem (raiz->esq);
        imprimir_PosOrdem (raiz->dir);
        printf (" %d",raiz->chave);
    }

}

void imprimir_ArvBinBusca(ArvBin* arv){
    printf ("Pre.:");
    imprimir_PreOrdem (arv->raiz);printf ("\n");
    printf ("In..:");
    imprimir_EmOrdem (arv->raiz);printf ("\n");
    printf ("Post:");
    imprimir_PosOrdem (arv->raiz);printf ("\n");

}

void liberar_no(Nodo* raiz){
    if (raiz!=NULL){
        liberar_no (raiz->esq);
        liberar_no (raiz->dir);
        free(raiz);
    }
}

void liberar_ArvBinBusca(ArvBin* arv){
    liberar_no (arv->raiz);
    free(arv);
}
int main() {
    int Case =0 , N=0 , valor;
    while(scanf ("%d",&Case)!=EOF){
        for(int i = 1; i<=Case;i++){
            ArvBin* Pai = criar_arv ();
            scanf("%d",&N);
            for (int j=0; j<N; j++){
                scanf ("%d",&valor);
                inserir_ArvBinBusca (Pai,valor);
            }
            setbuf (stdin,NULL);
            printf ("Case %d:\n",i);
            imprimir_ArvBinBusca (Pai);
            printf("\n");
            liberar_ArvBinBusca (Pai);
        }
    }

    return 0;
}