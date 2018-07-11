#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <utility>
#include <queue>
#include <list>
#define INFINITO 999999999


using namespace std;

typedef pair<int,int>edge;
typedef enum {Branco,Cinza}Cor;
class Grafos{
    int vertice;
    int *distancia;
    Cor *color;
    list<edge> *adj; // lista de adjacencia com Peso
    list<int> *adj1; // lista de adjacencia sem peso

public:
    explicit Grafos (int v);
    void adicionarEdge(int v, int a, int p);
    void Dijkstra(int S,int F);
    bool existeVizinhoListAdj(int v1, int v2);



};

Grafos::Grafos(int v) {
    this->vertice = v;
    adj = new list<edge>[v+1];
    adj1 = new list<int>[v+1];
    distancia = (int*)malloc((v+1)* sizeof(int));
}

void Grafos::adicionarEdge(int v, int a, int p){
    adj[v].push_back(edge(a,p));
    adj1[v].push_back(a);
}

void Grafos::Dijkstra(int S, int F){

    // Create a priority queue to store vertices that
    // are being preprocessed. This is weird syntax in C++.
    // Refer below link for details of this syntax
    // http://geeksquiz.com/implement-min-heap-using-stl/
    priority_queue< edge, vector <edge> , greater<edge> > pq;

    // Create a vector for distances and initialize all
    // distances as infinite (INF)
    for(int i = 1;i <= vertice;i++) distancia[i] = INFINITO; // definimos todas as distâncias como infinito, exceto a de S.
    distancia[S] = 0;

    // Insert source itself in priority queue and initialize
    // its distance as 0.
    pq.push(make_pair(0, S));


    /* Looping till priority queue becomes empty (or all
      distances are not finalized) */
    while (!pq.empty())
    {
        // The first vertex in pair is the minimum distance
        // vertex, extract it from priority queue.
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)
        int u = pq.top().second;
        pq.pop();

        // 'i' is used to get all adjacent vertices of a vertex
        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            // Get vertex label and weight of current adjacent
            // of u.
            int v = (*i).first;
            int weight = (*i).second;

            //  If there is shorted path to v through u.
            if (distancia[v] > distancia[u] + weight)
            {
                distancia[v] = distancia[u] + weight;// Updating distance of v
                    if(existeVizinhoListAdj(v,u)){
                      distancia[v]= distancia[v]- weight;
                    }
                    if ( v == F)
                        break;
                pq.push(make_pair(distancia[v], v));
            }
        }
    }


if (distancia[F]!=INFINITO)
    cout << distancia[F] << endl;
else
    cout << "Nao e possivel entregar a carta"<<endl;

}

bool Grafos::existeVizinhoListAdj(int v1, int v2) {
    if ( find( adj1[v1].begin(), adj1[v1].end(), v2) != adj1[v1].end() )
        return true;
    return false;
}

int main() {
    int N,E;
    int X,Y,H;
    int K,O,D;
   // cin >> N >> E;
    while ((scanf("%d %d",&N,&E))!=EOF){
        if (N==0 && E ==0)
            break;
        Grafos grafos(N);
        for (int i =1;i<=E;i++){
            cin >> X >> Y >> H;
            grafos.adicionarEdge(X,Y,H);
        }
        cin >> K;
        for(int y=1;y<=K;y++){
            cin>> O >> D;
            grafos.Dijkstra(O,D);
        }
        cout << "\n";
      //  cin >> N >> E;
    }
    return 0;
}