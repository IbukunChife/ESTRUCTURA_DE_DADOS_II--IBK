#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

typedef struct No{
    int info;
    No * next;
}Nodo;

typedef struct Table {
    Nodo **Tab;
    int size;
}Table;


Table* Criar_Hash(int n){
    Table* novo = (Table*)malloc(sizeof(Table));
    novo->Tab = (No**)malloc(n* sizeof(No*));
    novo->size =n;
    for (int i = 0; i <n; i++)
        novo->Tab[i]= NULL;
    return novo;
}

void inserir(Table* tabela, int posicao, int numero)
{
    Nodo* novo = new Nodo();
    novo->info = numero;
    if(tabela->Tab[posicao] != NULL){
        No* aus = tabela->Tab[posicao];
        while(aus->next!= NULL){
            aus = aus->next;
        }
        aus->next= novo;
    }
    else
        tabela->Tab[posicao] = novo;
    novo->next = NULL;
}

int mod(int n, int m)
{
    return n%m;
}

void imprime(Table* tabela)
{
    Nodo* aux;
    for(int i = 0; i < tabela->size; i++)
    {
        cout << i << " -> ";
        aux = tabela->Tab[i];
        while(aux != NULL)
        {
            cout << aux->info << " -> ";
            aux = aux->next;
        }
        cout << "\\" << "\n";
    }
}

int main() {
    int N, M, C, n, i, j;
    int posicao;
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d %d", &M, &C);
        Table *tabela = Criar_Hash(M);

        for (j = 0; j < C; j++) {
            scanf("%d", &n);
            posicao = mod(n, M);
            inserir(tabela, posicao, n);
        }
        imprime(tabela);
        if (i != N-1)
            cout << "\n";
    }

}