// Escriu totes les combinacions de n bits amb u uns.

#include <iostream>
#include <vector>
using namespace std;


typedef vector<int> VE;


int n;
VE V;


void f(int i, int z, int u) {
  if (z < 0 or u < 0) return;

  if (i == n) {
    for (int j = 0; j < n; ++j) cout << V[j];
    cout << endl;
    return;
  }

  V[i] = 0;
  f(i + 1, z - 1, u);
  V[i] = 1;
  f(i + 1, z, u - 1);
}


int main() {
  int u;
  cin >> n >> u;
  V = VE(n);
  f(0, n - u, u);
}
