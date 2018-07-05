#include <iostream>
#include <algorithm>
#include <list>
#include <queue>

using namespace std;

class Grafo{
    int V;
    list<int>*adj;
    queue<int>fila,fila1,fila2,fila3,fila4;
    queue<int>lin,lin1,lin2,lin3,lin4;
public:
    explicit Grafo(int V);
    void adicionarAresta(int v1, int v2);
    bool existeVizinho(int v1, int v2);
    bool verificar();
    void liberarListFila();
};

Grafo::Grafo(int V) {
    this->V = V;
    adj = new list<int>[V+1];
}

void Grafo::adicionarAresta(int v1, int v2) {
    adj[v1].push_back(v2);
}

bool Grafo::verificar(){
    long int num;
    int cont=0, linha =0;
    for(int j = 1; j<=5;j++){
        for(int i=1; i<=5;i++){
             num = count(adj[i].begin(),adj[i].end(),j);
             if (num != 0){
                 cont++;
                 if (cont == 1)
                     linha = i;
                 if (cont == 2)
                     linha = i;
             }
        }

        if (cont == 0){
            fila.push(j);
            //lin.push(j)
        }else if (cont == 1){
            fila1.push(j);
            lin1.push(linha);
        } else if(cont == 2){
            fila2.push(j);
            lin2.push(linha);
        }
        cont=0;
        linha =0;
    }

    if(!fila.empty()){
        long int tam = fila.size();
        int x = fila.front();
        if ( x == 5 || x == 1 ){

        }
        for(int x = primeiro; x < primeiro + 2; x++ ){

        }
        return true;
    }else if(!fila1.empty()){
        if( (abs (fila1.front() - fila1.back()) == 1)&& (abs (lin1.front() - lin1.back()) == 2) &&
            (fila1.front()!=5 && fila1.front()!=1) && (fila1.back()!=5 && fila1.back()!=1)){
            return true;
        }
    } else if(!fila2.empty()){
        if( (abs (fila2.front() - fila2.back()) == 2) && (abs (lin2.front() - lin2.back()) == 2) &&
            (fila2.front()!=5 && fila2.front()!=1) && (fila2.back()!=5 && fila2.back()!=1)){
            return true;
        }
    }
    return false;
}

bool Grafo::existeVizinho(int v1, int v2) {
    if(find(adj[v1].begin(),adj[v1].end(),v2)!= adj[v1].end())
        return true;
    return false;
}

void Grafo::liberarListFila(){
    while(!fila.empty())fila.pop();
    while(!fila1.empty())fila1.pop();
    while(!fila2.empty())fila2.pop();
    for (int i = 0; i < V ; ++i) {
        adj[i].clear();
       // while(!adj[i].empty())adj[i].pop_back();
    }
    //delete adj;
}

int main() {
    int Test;
    //int N,M;
    int A,B,C,D,E;
    Grafo grafo (5);
    cin>> Test;
    for (int i = 0; i < Test ; ++i) {
        for (int j=1; j <= 5 ;j++){
            cin >> A >> B >> C >> D >> E;
                if( A == 1)
                    grafo.adicionarAresta(j,1);
                if( B == 1)
                    grafo.adicionarAresta(j,2);
                if( C == 1)
                    grafo.adicionarAresta(j,3);
                if( D == 1)
                    grafo.adicionarAresta(j,4);
                if( E == 1)
                    grafo.adicionarAresta(j,5);
        }

        if (grafo.existeVizinho(1,1) && !grafo.existeVizinho(5,5))
                cout << "ROBBERS" << endl;
        else if (!grafo.existeVizinho(1,1) && grafo.existeVizinho(5,5))
                cout << "COP" << endl;
        else if (grafo.existeVizinho(1,1) && grafo.existeVizinho(5,5))
                cout << "ROBBERS" << endl;
        else{
            if (grafo.verificar())
                cout <<"COPS" << endl;
            else
                cout <<"ROBBERS" << endl;
        }
        grafo.liberarListFila();
    }
    return 0;
}

/*
3

0 0 0 0 1
1 1 0 1 1
0 1 0 0 1
0 0 1 0 0
1 1 0 0 0

0 0 0 0 1
1 1 0 0 1
0 1 0 0 0
0 0 0 1 1
1 1 0 0 0

0 0 0 0 1
1 1 0 0 1
0 1 0 0 0
0 0 1 1 1
1 1 0 0 0
 */
