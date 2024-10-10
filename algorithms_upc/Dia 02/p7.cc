// Escriu totes les maneres de posar n torres en un tauler n X n.


#include <iostream>
#include <vector>
using namespace std;


typedef vector<int> VE;


int n;
VE V, usat;


void f(int i) {
  if (i == n) {
    for (int k = 0; k < n; ++k) {
      for (int j = 0; j < n; ++j) cout << (j == V[k] ? 'T' : '.');
      cout << endl;
    }
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
