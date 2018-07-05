//
// Created by WizIbk on 01/07/18.
//
#include <iostream>
using namespace std;

typedef enum {
    Branco, Cinza, Preto
} Cor;

class Police {
    int V = 5;
    int mat[6][6];
public:
    explicit Police();

    void adicionarMatAdj(int i, int j);

    bool percorrer(int i, int j, int a, int b);

    void inicializarMatAdj();
};

Police::Police() {
    ;
}

void Police::adicionarMatAdj(int i, int j) {
    this->mat[i][j] = 1;
}

bool Police::percorrer(int i, int j, int a, int b) {
    if (mat[1][1] == 1)
        return false;
    else {

        if (i == 5 && j == 5) {
            return true;
        } else if (i < 5 && j < 5) {
   //         if (mat[i][j] == 0) { }
                if (mat[i + 1][j] == 0)
                    return percorrer(i + 1, j, i, j);
                else if (mat[i][j + 1] == 0)
                    return percorrer(i, j + 1, i, j + 1);
                else if (a == i - 1 && b == j) {

                    if (mat[i - 1][j + 1] == 0)
                        return percorrer(i - 1, j + 1, a, b);
                    else {
                        while (mat[a][b + 1] != 0) {
                            a--;
                        }
                        return percorrer(a, b + 1, a, b);
                    }
                } else if (a == i && b == j - 1) {
                    if (mat[i + 1][j - 1] == 0)
                        return percorrer(i + 1, j - 1, a, b);
                    else {
                        while (mat[a + 1][b] != 0) {
                            b--;
                        }
                        return percorrer(a + 1, b, a, b);
                    }
                }


        } else if (i == 5 && j < 5) {
            if (mat[i][j + 1] == 0 || (j + 1) == 5)
                return percorrer(i, j + 1, i, j);
        } else if (i < 5 && j == 5) {
            if (mat[i + 1][j] == 0 || (i + 1) == 5)
                return percorrer(i + 1, j, i, j);
        }
        return false;

    }
}

void Police::inicializarMatAdj() {
    for (int i = 0; i <= V; i++)
        for (int j = 0; j <= V; j++)
            mat[i][j] = 0;
}

int main() {
    int Test;
    int A, B, C, D, E;
    cin >> Test;
    for (int n = 0; n < Test; ++n) {
        Police police;
        police.inicializarMatAdj();
        for (int i = 1; i <= 5; i++) {
            cin >> A >> B >> C >> D >> E;
            if (A == 1)
                police.adicionarMatAdj(i, 1);
            if (B == 1)
                police.adicionarMatAdj(i, 2);
            if (C == 1)
                police.adicionarMatAdj(i, 3);
            if (D == 1)
                police.adicionarMatAdj(i, 4);
            if (E == 1)
                police.adicionarMatAdj(i, 5);
        }

        if (police.percorrer(1, 1, 5, 5))
            cout << "COPS" << endl;
        else
            cout << "ROBBERS" << endl;
    }
}
/*

0 0 1 1 1
1 0 0 0 0
0 0 1 0 0
0 1 1 1 0
0 0 1 0 1

0 0 0 1 1
0 1 0 0 1
0 1 0 1 1
0 1 0 0 1
1 0 1 0 0 */
