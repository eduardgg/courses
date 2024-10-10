// Algorisme de Floyd-Warshall. Calcula el cost minim d'anar
// de cada vertex i a cada vertex j en un graf amb costs positius.


#include <iostream>
#include <vector>
using namespace std;


const int INF = 1e8;


typedef vector<int> VE;
typedef vector<VE> VVE;


VVE M;


int main() {
    int n, m;
    while (cin >> n >> m) {
        VVE M(n, VE(n, INF));
        while (m--) {
            int x, y, c;
            cin >> x >> y >> c;
            M[x][y] = c;
        }
        for (int i = 0; i < n; ++i) M[i][i] = 0;

        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    M[i][j] = min(M[i][j], M[i][k] + M[k][j]);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) cout << ' ' << M[i][j];
            cout << endl;
        }
    }
}
