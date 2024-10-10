// Escriu totes les permutacions amb n elements.
// Codi ineficient.


#include <iostream>
#include <vector>
using namespace std;


typedef vector<int> VE;


int n;
VE V;


void f(int i) {
  if (i == n) {
    for (int k = 0; k < n; ++k) cout << ' ' << V[k];
    cout << endl;
    return;
  }

  for (int j = 0; j < n; ++j) {
    bool trobat = false;
    for (int k = 0; k < i; ++k)
      if (V[k] == j) trobat = true;
    if (not trobat) {
      V[i] = j;
      f(i + 1);
    }
  }
}


int main() {
  cin >> n;
  V = VE(n);
  f(0);
}
