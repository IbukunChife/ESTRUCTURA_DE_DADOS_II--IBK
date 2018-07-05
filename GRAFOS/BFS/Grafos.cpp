//
// Created by ibk_akaigen on 27/06/18.
//

#include "Grafos.h"
#include <queue>

using namespace std;

Grafos::Grafos(int v) {
    this->V = v;
    adj = new list<int>[v];
    color = (Cor*)malloc(v* sizeof(Cor));
    dist = (int*)malloc(v* sizeof(int));
    pai = (int*)malloc(v* sizeof(int));
    MAT = (int **) malloc(v * sizeof(int *));
    for (int i = 0; i < v; i++)
        MAT[i] = (int *) malloc(v * sizeof(int));
    for (int i =0 ;i<v; i++)
        for(int j=0; j<v;j++)
            MAT[i][j]=0;

}

void Grafos::adicionarListAdj(int v1, int v2) {
    adj[v1].push_back(v2);
}

int Grafos::obterGrauDeListAdj(int v) {
    return static_cast<int>(adj[v].size());
}

bool Grafos::existeVizinhoListAdj(int v1, int v2) {
    if ( find( adj[v1].begin(), adj[v1].end(), v2) != adj[v1].end() )
        return true;
    return false;
}

void Grafos::adicionarMatAdj(int i, int j){
    this->MAT[i][j]=1;
}

int Grafos::numeroDeAresta(int i){
    int contador=0;
    for (int j=0; j<this->V;j++){
        if(this->MAT[i][j]==1)
            contador++;
    }
    return contador;

}

void Grafos::adicionarListAres(int v1,int v2){
    aresta.push_back(make_pair(v1,v2));
}

void Grafos::inicializar(){
    for (int i=0; i<this->V;i++){
        color[i]= Branco;
        dist[i] = NULL;
        pai[i] = NULL;

    }

}

void Grafos::visitar( int y){
    if (color[y] == Branco){
        color[y] = Cinza;
        dist[y] = dist[W]+1;
        pai[y] = W;
        fila.push(y);
    }
}

void Grafos::BFS(int S){
    inicializar();
    color[S]= Cinza;
    dist[S]=0;
    fila.push(S);
    while(!fila.empty()){
        this->W = fila.front();
        fila.pop();
        for_each( adj[W].begin(),adj[W].end(),visitar);
        color[W]=Preto;
    }
}

void Grafos::imprimirCaminho(int s, int v){
    if (v==s)
        cout << s ;
    else if (pai[v] == NULL )
        cout << "\n Não exit um caminho de "s"para"v"exit\n";
    else
        imprimirCaminho(s,pai[v]);
    cout << v;
}
