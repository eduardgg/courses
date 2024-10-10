// Escriu la primera sequencia de 0s i 1s amb n bits sense dos 0s seguits.
// Sempre n'hi ha, pero si no n'hi hagues ho diria.


#include <iostream>
#include <vector>
using namespace std;


typedef vector<int> VE;


int n;
VE V;


bool f(int i) {
  if (i == n) {
    for (int j = 0; j < n; ++j) cout << V[j];
    cout << endl;
    return true;
  }

  if (i == 0 or V[i-1] != 0) {
    V[i] = 0;
    if (f(i + 1)) return true;
  }

  V[i] = 1;
  return f(i + 1);
}


int main() {
  cin >> n;
  V = VE(n);
  if (not f(0)) cout << "sense solucio" << endl;
}
