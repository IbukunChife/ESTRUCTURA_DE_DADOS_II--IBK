//
// Created by ibk_akaigen on 27/06/18.
//

#ifndef BFS_GRAFOS_H
#define BFS_GRAFOS_H

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

typedef enum{ Branco, Cinza,Preto}Cor;

class Grafos {
    int V;
    list <int> *adj;
    int ** MAT;
    int * dist;
    int * pai;
    vector < pair <int ,int> > aresta;
    Cor * color;
    // Elemento usado para a Busca BFS
    int W; //valor retirado da fila da busca
    queue<int> fila;


public:
    explicit Grafos(int i);
    void adicionarListAdj(int v1, int v2);
    void adicionarMatAdj(int i, int j);
    void adicionarListAres(int v1,int v2);
    int obterGrauDeListAdj(int v);
    bool existeVizinhoListAdj(int v1, int v2);
    int numeroDeAresta(int i );
    void inicializar();
    void visitar(int y);
    void BFS(int S);
    void imprimirCaminho(int s, int v);




};


#endif //BFS_GRAFOS_H
