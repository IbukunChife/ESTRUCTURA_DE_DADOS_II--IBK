
//Operações em ABP I

#include <stdio.h>
#include <stdlib.h>


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

int achar_primeiro_PreOrdem(Nodo* raiz){
    if(raiz !=NULL)
        return raiz->chave;

}

void imprimir_PreOrdem(Nodo* raiz ,int primeiro){
    if (raiz!=NULL){
        if(raiz->chave == primeiro)
            printf ("%c",raiz->chave);
        else
            printf (" %c",raiz->chave);
        imprimir_PreOrdem (raiz->esq, primeiro);
        imprimir_PreOrdem (raiz->dir,primeiro);
    }

}

int achar_primeiro_EnOrdem(Nodo* raiz){
    while(raiz->esq!=NULL){
        raiz= raiz->esq;
    }
    return raiz->chave;
}
void imprimir_EmOrdem(Nodo* raiz, int primeiro){
    if(raiz!=NULL){
        imprimir_EmOrdem (raiz->esq, primeiro);
        if(raiz->chave == primeiro)
            printf ("%c",raiz->chave);
        else
            printf (" %c",raiz->chave);
        imprimir_EmOrdem (raiz->dir, primeiro);
    }

}
int achar_primeiro_PostOrdem(Nodo* raiz){
    while(raiz->esq!=NULL){
        raiz = raiz->esq;
    }
    return raiz->chave;
}

void imprimir_PosOrdem(Nodo* raiz,int primeiro){
    if (raiz!=NULL){
        imprimir_PosOrdem (raiz->esq,primeiro);
        imprimir_PosOrdem (raiz->dir,primeiro);
        if (raiz->chave == primeiro)
            printf ("%c",raiz->chave);
        else
            printf (" %c",raiz->chave);
    }

}

void imprimir_ArvBinBusca(ArvBin* arv,int comando ){
    if( comando == 1){
        int primeiro_PreOrdem = achar_primeiro_PreOrdem (arv->raiz);
        imprimir_PreOrdem (arv->raiz,primeiro_PreOrdem);printf ("\n");
    }
    if( comando == 2){
        int primeiro_InOrdem = achar_primeiro_EnOrdem (arv->raiz);
        imprimir_EmOrdem (arv->raiz,primeiro_InOrdem);printf ("\n");
    }
    if(comando == 3){
        int primeiro_PostOrdem = achar_primeiro_PostOrdem (arv->raiz);
        imprimir_PosOrdem (arv->raiz,primeiro_PostOrdem);printf ("\n");
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
    char buffer[10], Case[8], valor;
    ArvBin* Pai = criar_arv ();
    while(scanf ("%[^\n]",buffer)!=EOF){
        sscanf (buffer,"%s %c", Case,&valor);
        if(Case[0]=='I' && Case[1] =='\0'){
            inserir_ArvBinBusca (Pai,valor);
        }else
        if(Case[0]=='P' && Case[1] =='\0'){
            if (busca (Pai->raiz,valor))
                printf ("%c existe\n",valor);
            else
                printf ("%c nao existe\n",valor);
        }else
        if(Case[0]=='P' && Case[1] =='R'){
            imprimir_ArvBinBusca (Pai,1);
        }else
        if(Case[0]=='I' && Case[1] =='N'){
            imprimir_ArvBinBusca (Pai,2);
        }else
        if(Case[0]=='P' && Case[1] =='O'){
            imprimir_ArvBinBusca (Pai,3);
        }
       setbuf (stdin,NULL);
    }
    liberar_ArvBinBusca (Pai);
    return 0;
}
