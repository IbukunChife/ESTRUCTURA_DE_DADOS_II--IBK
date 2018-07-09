#include <iostream>
#include <algorithm>
#include <utility>
#include <list>
#include <map>
#include <vector>


using namespace std;

class Grafos{
    int vertice;
    list<pair<int,int>> *adj;

public:
    explicit Grafos (int v);
    int adicionarVector(int v, int a, int p);
    void consultas(int a ,int b);



};

Grafos::Grafos(int v) {
    this->vertice = v;
    adj= new list[v+1];
 //   aresta = new vector[v+1];
}

Grafos::adicionarVector(int v, int a, int p){
    adj[v].push_back(make_pair(a,p));
}

Grafos::consultas(int a ,int b){
    for (pair<int, int> &t : adj[a]){
        if (t.first == b)
            cout<<
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}