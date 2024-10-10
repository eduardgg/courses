// Escriu totes les permutacions amb n elements.
// Codi eficient.


#include <iostream>
#include <vector>
using namespace std;


typedef vector<int> VE;


int n;
VE V, usat;


void f(int i) {
  if (i == n) {
    for (int k = 0; k < n; ++k) cout << ' ' << V[k];
    cout << endl;
    return;
  }

  for (int j = 0; j < n; ++j) {
    if (not usat[j]) {
      V[i] = j;
      usat[j] = true;
      f(i + 1);
      usat[j] = false;
    }
  }
}


int main() {
  cin >> n;
  V = VE(n);
  usat = VE(n, false);
  f(0);
}
