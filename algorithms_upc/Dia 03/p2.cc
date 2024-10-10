// Escriu una manera de posar n reines en un tauler n X n,
// o diu que no es pot.


#include <iostream>
#include <vector>
using namespace std;


typedef vector<int> VE;


int n;
VE V, col, dia1, dia2;


bool f(int i) {
  if (i == n) {
    for (int k = 0; k < n; ++k) {
      for (int j = 0; j < n; ++j) cout << (j == V[k] ? 'R' : '.');
      cout << endl;
    }
    cout << endl;
    return true;
  }

  for (int j = 0; j < n; ++j) {
    int d1 = i + j;
    int d2 = i - j + n - 1;
    if (not col[j] and not dia1[d1] and not dia2[d2]) {
      V[i] = j;
      col[j] = dia1[d1] = dia2[d2] = true;
      if (f(i + 1)) return true;
      col[j] = dia1[d1] = dia2[d2] = false;
    }
  }
  return false;
}


int main() {
  cin >> n;
  V = VE(n);
  col = VE(n, false);
  dia1 = dia2 = VE(2*n - 1, false);
  if (not f(0)) cout << "no es pot" << endl;
}
