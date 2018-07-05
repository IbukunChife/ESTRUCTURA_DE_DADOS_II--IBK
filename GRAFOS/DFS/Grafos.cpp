//
// Created by WizIbk on 01/07/18.
//

#include <iostream>
#include "Grafos.h"


using namespace std;

Grafos::Grafos(int v) {
    this->V = v;
    adj = new list<int>[v+1];
    color = (Cor*)malloc((v+1)* sizeof(Cor));
    tempo_inicial = (int*)malloc((v+1)* sizeof(int));
    tempo_final = (int*)malloc((v+1)* sizeof(int));
    comp = (int*)malloc((v+1)* sizeof(int));
    pai = (int*)malloc((v+1)* sizeof(int));
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
    for (int i=1; i<=this->V;i++){
        color[i]= Branco;
        tempo_inicial[i] = NULL;
        tempo_final[i] = NULL;
        pai[i] = 0;
        time = 0;

    }

}

void Grafos::DFS_Explore(int a ,int u ){
    if (color[a] == Branco){
        pai[a]= u;
        DFS_visitar(a);
    }
}


void Grafos::DFS_visitar( int y){
    time = time +1;
    tempo_inicial[y]= time;
    color[y]= Cinza;
    for (int t : adj[y]){
        DFS_Explore(t,y);
    }
    color[y]= Preto;
    time = time+1;
    tempo_final[y]= time;
    comp[y]= contadorComponente;
}

void Grafos::DFS(){
    inicializar();
    for (int i=1; i<=this->V;i++){
        if (color[i] == Branco){
            contadorComponente++;
            DFS_visitar(i);
        }
    }
}

void Grafos::imprimir(){
    cout << "pai\n";
    for (int i = 1; i <= V; i++ ){
        cout << pai[i];
    }

    cout << "\nTempo_Inicial\n";
    for (int i = 1; i <= V; i++ ){
        cout << tempo_inicial[i] ;
    }

    cout << "\nTempo_Final\n";
    for (int i = 1; i <= V; i++ ){
        cout << tempo_final[i];
    }

    cout << "\nComponente\n";
    for (int i = 1; i <= V; i++ ){
        cout << comp[i];
    }
}