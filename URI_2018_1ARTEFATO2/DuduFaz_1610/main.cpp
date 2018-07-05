
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

typedef enum{ Branco, Cinza,Preto}Cor;

class Grafos {
    int V;
  //  int time=0;
    list <long long int> *adj;
  //  int contadorComponente=0;
   // int * comp;
    Cor * color;
  //  int * pai;
    int colisao = 0;

public:

    explicit Grafos(int v);
    void adicionarListAdj(int v1, int v2);
    void inicializar();
    void DFS_Explore(int a, int u);
    void DFS_visitar(int y);
    void DFS();
    bool verificarLoop();
    void liberarList();


};


Grafos::Grafos(int v) {
    this->V = v;
    adj = new list< long long int>[v+1];
    color = (Cor*)malloc((v+1)* sizeof(Cor));
  //  comp = (int*)malloc((v+1)* sizeof(int));
 //   pai = (int*)malloc((v+1)* sizeof(int));

}
void Grafos::adicionarListAdj(int v1, int v2){
    adj[v1].push_back(v2);
}
void Grafos::inicializar(){
    for (int i=1; i<=this->V;i++){
        color[i]= Branco;
    //    pai[i] = -1;
    }
}
void Grafos::DFS_Explore(int a, int u){
    if (color[a] == Branco){
//        pai[a]= u;
        DFS_visitar(a);
    }
    if(color[a] == Cinza){
            colisao++;
    }
}
void Grafos::DFS_visitar(int y){
    color[y]= Cinza;
    for (long long int t : adj[y]){
        DFS_Explore(t,y);
    }
    color[y]= Preto;
  //  comp[y]= contadorComponente;
}
void Grafos::DFS(){
    inicializar();
    for (int i=1; i<=this->V;i++){
        if (color[i] == Branco){
       //     pai[i]=0;
            DFS_visitar(i);
        }
    }
}

bool Grafos::verificarLoop(){
    DFS();
    if (colisao == 0)
        return false;
    else
        return true;
/*    cout << "\n\n";
    for (int i = 1; i <= V; i++ ){
            cout << comp[i];
    }
    return true;*/
}

void Grafos::liberarList(){
    colisao =0;
    for (int i = 0; i < V ; ++i) {
        adj[i].clear();
    }
    free(color);
}

int main() {
    int Test;
    long long int N,M;
    long long int A,B;
    cin>> Test;
    for (int i = 0; i < Test ; ++i) {
        cin >> N >> M;
        Grafos grafo (N);
        for (int (i) = 0; (i) < M ; ++(i)) {
            cin >> A >> B;
            grafo.adicionarListAdj(A,B);
        }
        if (grafo.verificarLoop())
            cout <<"SIM" << endl;
        else
            cout <<"NÃO" << endl;
        grafo.liberarList();
    }
    return 0;
}