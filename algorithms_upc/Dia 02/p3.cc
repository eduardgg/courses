// Escriu totes les permutacions amb n elements.
// Codi molt ineficient.


#include <iostream>
#include <vector>
using namespace std;


typedef vector<int> VE;


int n;
VE V;


void f(int i) {
  if (i == n) {
    for (int j = 0; j < n; ++j) {
      int q = 0;
      for (int k = 0; k < n; ++k)
        if (V[k] == j) ++q;
      if (q != 1) return;
    }
    for (int k = 0; k < n; ++k) cout << ' ' << V[k];
    cout << endl;
    return;
  }

  for (int j = 0; j < n; ++j) {
    V[i] = j;
    f(i + 1);
  }
}


int main() {
  cin >> n;
  V = VE(n);
  f(0);
}
