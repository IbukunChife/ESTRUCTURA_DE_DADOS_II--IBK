#include <iostream>
#include "Grafos.h"


using namespace ::std;
int main() {
        // criando um grafo de 4 vértices
        Grafos *grafo = new Grafos(4);

        // adicionando as arestas
        grafo->adicionarListAdj(0, 3);
        grafo->adicionarListAdj(1, 2);
        grafo->adicionarListAdj(3, 1);
        grafo->adicionarListAdj(3, 2);

        // mostrando os graus de saída
        cout << "Grau de saida do vertice 1: " << grafo->obterGrauDeListAdj(1);
        cout << "\nGrau de saida do vertice 3: " << grafo->obterGrauDeListAdj(3);

        // verifica se existe vizinhos
        if(grafo->existeVizinhoListAdj(0, 1))
            cout << "\n\n1 eh vizinho de 0\n";
        else
            cout << "\n\n1 NAO eh vizinho de 0\n";

        if(grafo->existeVizinhoListAdj(0, 2))
            cout << "2 eh vizinho de 0\n";
        else
            cout << "2 NAO eh vizinho de 0\n";

        return 0;
}