//
// Created by WizIbk on 01/07/18.
//

#ifndef DFS_GRAFOS_H
#define DFS_GRAFOS_H

#include <iostream>
#include <list>
#include <stack>
#include <utility>
#include <algorithm>
#include <vector>


using namespace std;

typedef enum{ Branco, Cinza,Preto}Cor;

class Grafos {
    int V;
    int time;
    list <int> *adj;
    int ** MAT;
    int * tempo_inicial;
    int * tempo_final;
    int * pai;
    int contadorComponente=0;
    int * comp;
    Cor * color;

    vector < pair <int ,int> > aresta;
    // Elemento usado para a Busca BFS
    int W; //valor retirado da fila da busca


public:

    explicit Grafos(int i);
    void adicionarListAdj(int v1, int v2);
    void adicionarMatAdj(int i, int j);
    void adicionarListAres(int v1,int v2);
    int obterGrauDeListAdj(int v);
    bool existeVizinhoListAdj(int v1, int v2);
    int numeroDeAresta(int i );
    void inicializar();
    void DFS_Explore(int a, int u);
    void DFS_visitar(int y);
    void DFS();
    void imprimir();


};


#endif //DFS_GRAFOS_H
