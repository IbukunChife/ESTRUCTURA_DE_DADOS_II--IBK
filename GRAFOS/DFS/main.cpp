#include <iostream>
#include "Grafos.h"


using namespace ::std;
int main() {
    // criando um grafo de 4 vértices
    Grafos *grafo = new Grafos(6);

    // adicionando as arestas
    grafo->adicionarListAdj(1, 2);
    grafo->adicionarListAdj(1, 3);
    grafo->adicionarListAdj(3, 2);
    grafo->adicionarListAdj(2, 4);
    grafo->adicionarListAdj(4, 3);
    grafo->adicionarListAdj(5, 4);
    grafo->adicionarListAdj(5, 6);
    grafo->adicionarListAdj(6, 6);
    grafo->DFS();
    cout <<"\n \n";
    grafo->imprimir();

    return 0;
}