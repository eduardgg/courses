// Compta totes les sequencies de 0s i 1s amb n bits
// sense dos 0s seguits de forma eficient.


#include <iostream>
#include <vector>
using namespace std;


typedef vector<int> VE;


int n;
VE V;


int f(int i) {
  if (i == n) return 1;

  int res = 0;
  if (i == 0 or V[i-1] != 0) {
    V[i] = 0;
    res = f(i + 1);
  }

  V[i] = 1;
  return res + f(i + 1);
}


int main() {
  cin >> n;
  V = VE(n);
  cout << f(0) << endl;
}
