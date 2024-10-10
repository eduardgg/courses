// Calcula el nombre de maneres de donar canvi x
// amb les monedes M[0], M[n-1], suposant que es poden repetir.


#include <iostream>
#include <vector>
using namespace std;


typedef vector<int> VE;
typedef vector<VE> VVE;


VE M;
VVE R;


int f(int i, int z) {
    if (z < 0) return 0;
    int& res = R[i][z];
    if (res != -1) return res;
    if (i == 0) return res = (z == 0);
    return res = f(i, z - M[i-1]) + f(i - 1, z);
}


int main() {
    int n, x;
    while (cin >> n >> x) {
        M = VE(n);
        for (int i = 0; i < n; ++i) cin >> M[i];
        R = VVE(n + 1, VE(x + 1, -1));
        cout << f(n, x) << endl;
    }
}
