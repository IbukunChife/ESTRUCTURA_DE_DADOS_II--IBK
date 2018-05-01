/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    char chave;
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

Nodo* criar_no(char valor){
    Nodo* novo = (Nodo*)malloc (sizeof (Nodo));
    novo->chave = valor;
    novo->esq= novo->dir= NULL;
    return novo;
}

static Nodo* inserir_no (Nodo* raiz, char valor){
    if(raiz==NULL){
        raiz = criar_no (valor);
    }else if( valor< raiz->chave){
        raiz->esq = inserir_no (raiz->esq,valor);
    }else if(valor > raiz->chave){
        raiz->dir = inserir_no (raiz->dir,valor);
    }
    return raiz;
}

void inserir_ArvBinBusca(ArvBin* arv, char valor){
    arv->raiz = inserir_no (arv->raiz,valor);
}

Nodo* busca(Nodo* raiz, char k){
    while(raiz!=NULL && raiz->chave !=k){
        if (k<raiz->chave){
            raiz= raiz->esq;
        } else{
            raiz= raiz->dir;
        }
    }
    return raiz;
}

void imprimir_PreOrdem(Nodo* raiz){
    if (raiz!=NULL){
        printf ("%c",raiz->chave);
        imprimir_PreOrdem (raiz->esq);
        imprimir_PreOrdem (raiz->dir);
    }

}

void imprimir_EmOrdem(Nodo* raiz){
    if(raiz!=NULL){
        imprimir_EmOrdem (raiz->esq);
        printf ("%c",raiz->chave);
        imprimir_EmOrdem (raiz->dir);
    }

}

void imprimir_PosOrdem(Nodo* raiz){
    if (raiz!=NULL){
        imprimir_PosOrdem (raiz->esq);
        imprimir_PosOrdem (raiz->dir);
        printf ("%c",raiz->chave);
    }

}

void imprimir_ArvBinBusca(ArvBin* arv, char * comando ){
    if(strcmp (comando,"PREFIXA")== 0){
        imprimir_PreOrdem (arv->raiz);printf ("\n");
    }
    if(strcmp (comando,"INFIXA")== 0){
        imprimir_EmOrdem (arv->raiz);printf ("\n");
    }
    if(strcmp (comando,"POSFIXA")== 0){
        imprimir_PosOrdem (arv->raiz);printf ("\n");
    }
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
    char buffer[10]="", Case[7] = "" , valor;
    ArvBin* Pai = criar_arv ();
    while(scanf ("%[^\n]",buffer)!=EOF){
        sscanf (buffer,"%s %c", Case,&valor);
        if(strcmp (Case,"I")== 0){
            inserir_ArvBinBusca (Pai,valor);
        }
        if(strcmp (Case,"P")== 0){
            if (busca (Pai->raiz,valor))
                printf ("%c existe\n",valor);
            else
                printf ("%c nao existe\n",valor);
        }
        if(strcmp (Case,"INFIXA")== 0){
            imprimir_ArvBinBusca (Pai,Case);
        }
        if(strcmp (Case,"PREFIXA")== 0){
            imprimir_ArvBinBusca (Pai,Case);
        }
        if(strcmp (Case,"POSFIXA")== 0){
            imprimir_ArvBinBusca (Pai,Case);
        }
        setbuf (stdin,NULL);
    }
    liberar_ArvBinBusca (Pai);
    return 0;
}*/