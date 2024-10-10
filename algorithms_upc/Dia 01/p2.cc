// Escriu totes les sequencies de 0s i 1s amb n bits
// amb l'estil de codi de l'assignatura.


#include <iostream>
#include <vector>
using namespace std;


typedef vector<int> VE;


int n;
VE V;


void f(int i) {
  if (i == n) {
    for (int j = 0; j < n; ++j) cout << V[j];
    cout << endl;
    return;
  }

  V[i] = 0;
  f(i + 1);
  V[i] = 1;
  f(i + 1);
}


int main() {
  cin >> n;
  V = VE(n);
  f(0);
}
