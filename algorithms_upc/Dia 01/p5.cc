// Compta totes les sequencies de 0s i 1s amb n bits
// sense dos 0s seguits de forma ineficient.


#include <iostream>
#include <vector>
using namespace std;


typedef vector<int> VE;


int n;
VE V;


int f(int i) {
  if (i == n) {
    for (int j = 1; j < n; ++j) if (V[j] == 0 and V[j-1] == 0) return 0;
    return 1;
  }

  V[i] = 0;
  int res = f(i + 1);
  V[i] = 1;
  return res + f(i + 1);
}


int main() {
  cin >> n;
  V = VE(n);
  cout << f(0) << endl;
}
