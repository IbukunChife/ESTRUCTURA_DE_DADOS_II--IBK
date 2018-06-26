//
// Created by WizIbk on 26/06/18.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HashD.h"


HashD* criar_Tab(int n){
    HashD * novo = (HashD*)malloc(sizeof(HashD));
    novo->chaves= (name*)malloc(n* sizeof(name));
    for (int i = 0 ; i<n; i++)
        strcpy(novo->chaves[i].nome,"-1");
    novo->size = n;
    return novo;
}

HashD* inserir_No_chaves(HashD * H, char * name){
    int i=1;
    int position = (int)name[0] % H->size;
    while ( position <= H->size && strcmp(H->chaves[position].nome,"-1") !=0 &&  strcmp(H->chaves[position].nome ,"-2")!=0  ) {
        position = ( position + i * ( 1+ (((int)name[0]) % ((H->size)-2))) )% H->size;
        i++;
    }
    if(strcmp(H->chaves[position].nome,"-1")==0 || strcmp(H->chaves[position].nome,"-2")==0)
        strcpy(H->chaves[position].nome,name );
    else
        printf("A tabela não disponha mais espaço para armazenar nome \n");
    return H;
}

HashD* remover_No_chaves(HashD* H, char* name){
    int i=1;
    int position = (int)name[0] % H->size;
    while (position <= H->size && strcmp(H->chaves[position].nome,name)!=0) {
        position = ( position + i * ( 1+ (((int)name[0]) % ((H->size)-2))) )% H->size;
        i++;
    }
    if (strcmp(H->chaves[position].nome,name)==0)
        strcpy(H->chaves[position].nome, "-2" );
    else
        printf("O nome não figura dentro na Tabela");
    return H;
}

void imprimir_Hash(HashD* H) {
    for (int i = 0; i < H->size; i++) {
        if (strcmp(H->chaves[i].nome,"-1")==0 || strcmp(H->chaves[i].nome,"-2")==0) {
                printf("position:%d nome : Vazia\n",i);
        } else{
            printf("position:%d nome : %s \n",i,H->chaves[i].nome);
        }
    }
}

void liberar_Tab(HashD* H){
        free(H->chaves);
}