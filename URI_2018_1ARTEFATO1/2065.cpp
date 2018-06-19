/**
Referencia https://www.youtube.com/watch?v=-zmJmCkBX8w
*/
#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(){
    int n, m, i; //n, funcionarios; m, clientes
    int v[10001];//velocidade de cada atendente

    scanf("%d %d", &n, &m);

    for (i = 1; i <= n; i++)
        scanf("%d", &v[i]);

    int resp = 0;// resposta

    priority_queue< pair<int, int > > fila; // fila de prioridades de uma par int int

    for(i = 1; i <= n; i++) // todos os caixas livres e o id
        fila.push(make_pair( 0, -i));

    while(m--){
        int qnt;
        scanf("%d", &qnt); // qnt de objetos

        int id = -fila.top().second; // o id do primeiro da fila
        int livre = -fila.top().first; // quando o caixa estara livre
        fila.pop(); // retira o primeiro cliente
        fila.push(make_pair( -(livre + v[id]*qnt), -id )); // mostra quando ele sera livre novamente

        resp = max( resp, (livre + v[id]*qnt));
    }
    printf("%d\n", resp);

    return 0;
}
