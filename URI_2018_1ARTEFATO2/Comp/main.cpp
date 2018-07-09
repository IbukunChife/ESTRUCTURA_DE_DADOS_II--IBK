#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <iterator>

using namespace std;

typedef enum {
    Branco, Cinza
} Cor;

class Grafos {
    int vertice;
    map<int, char>::iterator it;
    map<char, int> Alpha1{{'a', 1},
                          {'b', 2},
                          {'c', 3},
                          {'d', 4},
                          {'e', 5},
                          {'f', 6},
                          {'g', 7},
                          {'h', 8},
                          {'i', 9},
                          {'j', 10},
                          {'k', 11},
                          {'l', 12},
                          {'m', 13},
                          {'n', 14},
                          {'o', 15},
                          {'p', 16},
                          {'q', 17},
                          {'r', 18},
                          {'s', 19},
                          {'t', 20},
                          {'u', 21},
                          {'v', 22},
                          {'w', 23},
                          {'x', 24},
                          {'y', 25},
                          {'z', 26}};
    map<int, char> Alpha2{{1,  'a'},
                          {2,  'b'},
                          {3,  'c'},
                          {4,  'd'},
                          {5,  'e'},
                          {6,  'f'},
                          {7,  'g'},
                          {8,  'h'},
                          {9,  'i'},
                          {10, 'j'},
                          {11, 'k'},
                          {12, 'l'},
                          {13, 'm'},
                          {14, 'n'},
                          {15, 'o'},
                          {16, 'p'},
                          {17, 'q'},
                          {18, 'r'},
                          {19, 's'},
                          {20, 't'},
                          {21, 'u'},
                          {22, 'v'},
                          {23, 'w'},
                          {24, 'x'},
                          {25, 'y'},
                          {26, 'z'}};
    list<int> *adj;
    int *comp;
    int contador;
    Cor *color;

public:
    explicit Grafos(int v);

    void adicionarListAdj(char v1, char v2);

    void inicializar();

    void DFS_Explore(int a);

    void DFS_visitar(int y);

    void DFS();

    void Resultados();

};

Grafos::Grafos(int v) {
    this->vertice = v;
    adj = new list<int>[v + 1];
    color = (Cor *) malloc((v + 1) * sizeof(Cor));
    comp = (int *) malloc((v + 1) * sizeof(int));
}

void Grafos::adicionarListAdj(char v1, char v2) {
    adj[Alpha1[v1]].push_back(Alpha1[v2]);
    adj[Alpha1[v2]].push_back(Alpha1[v1]);

}

void Grafos::inicializar() {
    contador = 0;
    for (int i = 1; i <= this->vertice; i++) {
        color[i] = Branco;
        comp[i] = -1;
    }

}

void Grafos::DFS_Explore(int a) {
    if (color[a] == Branco) {
        DFS_visitar(a);
    }
}

void Grafos::DFS_visitar(int y) {
    color[y] = Cinza;
    for (int t: adj[y]) {
        DFS_Explore(t);
    }
    comp[y] = contador;
}

void Grafos::DFS() {
    inicializar();
    for (int i = 1; i <= vertice; i++) {
        if (color[i] == Branco) {
            contador++;
            DFS_visitar(i);
        }
    }
}

void Grafos::Resultados() {
    for (int i = 1; i <= contador; i++) {
        for (int j = 1; j <= vertice; j++) {
            if (comp[j] == i) {
                cout << Alpha2[j] << ",";
            }
        }
        cout << "\n";
    }
    cout << contador << " connected components" << endl;
}


int main() {
    int test;
    int V, E;
    char A, B;
    cin >> test;
    for (int x = 1; x <= test; x++) {
        cin >> V >> E;
        Grafos grafos(V);
        for (int i = 1; i <= E; i++) {
            cin >> A >> B;
            grafos.adicionarListAdj(A, B);
        }
        grafos.DFS();
        cout << "Case #" << x << ":" << endl;
        grafos.Resultados();
        cout << "\n";

    }

    return 0;
}