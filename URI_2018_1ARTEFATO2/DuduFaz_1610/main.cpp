#include <iostream>
#include <algorithm>
#include <list>
#include <queue>

using namespace std;

class Grafo{
    int V;
    list<int>*adj;
    queue<int>fila,fila1,fila2;
public:
    explicit Grafo(int V);
    void adicionarAresta(int v1, int v2);
    bool existeVizinho(int v1, int v2);
    void adicionarFila(int v);
    bool verificarLoop();
    void liberarListFila();
};

Grafo::Grafo(int V) {
    this->V = V;
    adj = new list<int>[V+1];
}

void Grafo::adicionarAresta(int v1, int v2) {
    adj[v1].push_back(v2);
}

void Grafo::adicionarFila(int v) {
    fila.push(v);
    fila1.push(v);
}

bool Grafo::verificarLoop(){
    int size = (int)fila.size();
    for(int x =0;x<size;x++){
        int w = fila.front();
        fila.pop();
        fila1.pop();
        if (fila1.empty()){
            return false;
        } else{
            while(!fila1.empty()){
                int aus = fila1.front();
                fila2.push(aus);
                fila1.pop();
                if (existeVizinho(aus,w))
                    return true;
            }
        }
        fila2.push(w);
        while(!fila2.empty()){
            fila1.push(fila2.front());
            fila2.pop();
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
    for (int i = 0; i < V ; ++i) {
        adj[i].clear();
       // while(!adj[i].empty())adj[i].pop_back();
    }
    //delete adj;
}

int main() {
    int Test;
    int N,M;
    int A,B;
    cin>> Test;
    for (int i = 0; i < Test ; ++i) {
        cin >> N >> M;
        Grafo grafo (N);
        for (int (i) = 0; (i) < M ; ++(i)) {
            cin >> A >> B;
            grafo.adicionarAresta(A,B);
            grafo.adicionarFila(A);
        }
        if (grafo.verificarLoop())
            cout <<"SIM" << endl;
        else
            cout <<"NÃO" << endl;
        grafo.liberarListFila();
    }
    return 0;
}