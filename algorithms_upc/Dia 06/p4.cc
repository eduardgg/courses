// Calcula el nombre de maneres de donar canvi x
// amb les monedes M[0], M[n-1], suposant que no es poden repetir.
// Versio iterativa senzilla.


#include <iostream>
#include <vector>
using namespace std;


typedef vector<int> VE;
typedef vector<VE> VVE;


int main() {
    int n, x;
    while (cin >> n >> x) {
        VE M(n);
        for (int i = 0; i < n; ++i) cin >> M[i];
        VE R(x + 1, 0);
        R[0] = 1;
        for (int i = 1; i <= n; ++i)
            for (int j = x; j >= M[i-1]; --j)
                R[j] += R[j - M[i-1]];
        cout << R[x] << endl;
    }
}
