// Escriu totes les sequencia de 0s i 1s amb n bits sense dos 0s seguits.


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

  if (i == 0 or V[i-1] != 0) {
    V[i] = 0;
    f(i + 1);
  }

  V[i] = 1;
  f(i + 1);
}


int main() {
  cin >> n;
  V = VE(n);
  f(0);
}
