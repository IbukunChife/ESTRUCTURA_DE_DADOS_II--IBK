
//Percurso em Árvore por Nível

#include <stdio.h>
#include <stdlib.h>
//**************************************Codigo da Arvore*******************************//

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
    novo->esq = novo->dir= NULL;
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

//***********************************Codigo da Fila*************************************//
typedef struct lista {
    Nodo* raiz ;
    struct lista * prox;
}Lista;

typedef struct fila{
    Lista* ini;
    Lista* fim;
    int tam;
}Fila;

Fila* criar_fila(){
    Fila* f = (Fila *)malloc(sizeof(Fila));
    f->fim =f->ini=NULL;
    f->tam = 0;
    return f;
}
void  inserir_fila (Fila* f, Nodo* raiz){
    Lista * novo =(Lista *)malloc(sizeof(Lista));
    novo->raiz = raiz;
    novo->prox = NULL;
    if(f->fim!= NULL){
        f->fim->prox=novo;
    } else{
        f->ini = novo;
    }
    f->fim= novo;
    f->tam++;
}

int fila_vazia(Fila* f ){
    return (f->tam == 0);
}

Nodo* retirar_fila(Fila* f){
    Lista* aux;
    Nodo* end;
    if(fila_vazia(f)){
        printf("Fila vazia.\n");
        exit(1);
    }
    aux = f->ini;
    end = aux->raiz;
    f->ini =  aux->prox;
    if (f->ini == NULL){
        f->fim = NULL;
    }
    f->tam--;
    free(aux);
    return end;
}

void liberar_fila(Fila * f){
    Lista* q = f->ini;
    while(q!=NULL){
        Lista* t = q->prox;
        free(q);
        q= t;
    }
    free(f);
}
//************************************IMPRIMIR EM LARGURA ***************************//

void imprimir_Em_Largura(Nodo* raiz){
    Fila * f = criar_fila();
    inserir_fila(f,raiz);
    while (!fila_vazia(f)){
        Nodo* p = retirar_fila(f);
        if (p!=NULL){
            if(p->chave == raiz->chave)
                printf("%d", p->chave);
            else
            printf(" %d", p->chave);
            inserir_fila(f,p->esq);
            inserir_fila(f,p->dir);
        }
    }
    printf("\n");
    liberar_fila(f);

}

void imprimir_ArvBinBusca(ArvBin* arv){
    imprimir_Em_Largura (arv->raiz);
}
//**************************************** MAIN ************************************//
int main() {
    int Case =0 , N=0 , valor;
    while(scanf ("%d",&Case)!=EOF){
        if (Case>=0 && Case <= 1000){
            for(int i = 1; i<=Case;i++){
                ArvBin* Pai = criar_arv ();
                scanf("%d",&N);
                if (N>=1 && N<=500){
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
        }
    }

    return 0;
}
