#include <iostream>
#include <vector>
using namespace std;


typedef long long ll;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef vector<char> VC;
typedef vector<VC> VVC;


int n, m;
VVC M;
VVL F;


// # maneres d'anar de (i, j) fins a (0,0) ...
ll f(int i, int j) {
    if (i < 0 or j < 0) return 0;
    ll& res = F[i][j];
    if (res != -1) return res;
    if (M[i][j] == 'X') return res = 0;
    if (i == 0 and j == 0) return res = 1;
    return res = f(i - 1, j) + f(i, j - 1);
}


int main() {
    int n, m;
    while (cin >> n >> m) {
        M = VVC(n, VC(m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) cin >> M[i][j];
        F = VVL(n, VL(m, -1));
        cout << f(n - 1, m - 1) << endl;
    }
}
