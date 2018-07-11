
#include <bits/stdc++.h>

using namespace std;
typedef struct no{
    int distancia;
    int verticeA, verticeB;
}Edge;
bool comparar(Edge a, Edge b){ return a.distancia < b.distancia;}

class PNoel {
    int size;
    int *pai;
    int *peso;
    vector <Edge> *aresta;
    vector <Edge> *Kruskal;

public:
    explicit PNoel(int v, int M);
    void adicionarEdge();
    int find(int x);
    void join(int a, int b);
    void Sorted();
    void CreateTree();
    void Imprimir();
};


PNoel::PNoel(int v,int M ){
    size = v;
    aresta = new vector<Edge>[M];
    Kruskal = new vector<Edge>[v];
    pai = (int*)malloc((v+1)* sizeof(int));
    peso = (int*)malloc((v+1)* sizeof(int));
    for (int i = 1; i <= v; i++)
        pai[i] = i;
}

void PNoel::adicionarEdge(){
    vector <Edge>::iterator i;
    for (i = aresta->begin(); i !=aresta->end(); i++)
        cin >> (*i).verticeA >> (*i).verticeB >> (*i).distancia ;
}

int PNoel::find(int x){
    if (pai[x]==x) return x;
    return  pai[x] = find(pai[x]);
}

void PNoel::join(int a, int b) {
    a = find(a);
    b = find(b);

    if (peso[a] < peso[b]) pai[a]=b;
    else if (peso[b]<peso[a]) pai[b]=a;
    else{
        pai[a]=b;
        peso[b]++;
    }

}

void PNoel::Sorted() {
    sort(aresta->begin(),aresta->end(),comparar);
}

void PNoel::CreateTree(){
    int tam=0;
    vector <Edge>::iterator i;
    for (i = aresta->begin(); i !=aresta->end(); i++){
        if (find ( (*i).verticeA ) != find((*i).verticeB)){
            join ((*i).verticeA , (*i).verticeB);
            Kruskal[++tam].push_back(*i);
        }
    }

}

void PNoel::Imprimir(){
    int min ;
    vector <Edge>::iterator i;
    for (i = Kruskal->begin(); i !=Kruskal->end(); i++){
         min += (*i).distancia;
    }
    cout << min << endl;
}

int main() {
    int N,M;
    while ((scanf("%d %d",&N,&M))!=EOF){
     if (N==0 && M==0)
         break;
     PNoel noel(N,M);
     noel.adicionarEdge();
     noel.Sorted();
     noel.CreateTree();
     noel.Imprimir();
    }
    return 0;
}