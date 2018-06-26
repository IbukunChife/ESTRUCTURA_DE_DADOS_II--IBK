//
// Created by WizIbk on 26/06/18.
//

#ifndef HASHDUPLA_HASHD_H
#define HASHDUPLA_HASHD_H

typedef struct names{
    char nome[20];
}name;

typedef struct hash{
    name *chaves;
    int size;
}HashD;

HashD* criar_Tab(int n);
HashD* inserir_No_chaves(HashD * H, char * name);
HashD* remover_No_chaves(HashD* H, char* name);
void imprimir_Hash(HashD* H);
void liberar_Tab(HashD* H);

#endif //HASHDUPLA_HASHD_H
