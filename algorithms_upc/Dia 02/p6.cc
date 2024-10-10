// Compta quantes permutacions hi ha amb n elements.


#include <iostream>
#include <vector>
using namespace std;


typedef vector<int> VE;


int n;
VE V, usat;


int f(int i) {
  if (i == n) return 1;

  int res = 0;
  for (int j = 0; j < n; ++j) {
    if (not usat[j]) {
      V[i] = j;
      usat[j] = true;
      res += f(i + 1);
      usat[j] = false;
    }
  }
  return res;
}


int main() {
  cin >> n;
  V = VE(n);
  usat = VE(n, false);
  cout << f(0) << endl;
}
