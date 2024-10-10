// Calcula els nombres binomials eficientment, de baix a dalt.


#include <iostream>
#include <vector>
using namespace std;


const int N = 51;


typedef long long ll;
typedef vector<ll> VL;
typedef vector<VL> VVL;


VVL C(N, VL(N));


int main() {
  for (int i = 0; i < N; ++i) C[i][0] = C[i][i] = 1;
  for (int i = 0; i < N; ++i)
    for (int j = 1; j < i; ++j) C[i][j] = C[i-1][j-1] + C[i-1][j];

  int n, x;
  while (cin >> n >> x) cout << n << ' ' << x << ' ' << C[n][x] << endl;
}
