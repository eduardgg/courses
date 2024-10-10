// Escriu tots els subconjunts que sumen suma,
// i compta quants n'hi ha. Codi millor que l'anterior.


#include <iostream>
#include <vector>
using namespace std;


typedef vector<int> VE;


int n;
VE V, triat;


int f(int i, int falta) {
  if (i == n) {
    if (falta != 0) return 0;

    for (int j = 0; j < n; ++j)
      if (triat[j]) cout << ' ' << V[j];
    cout << endl;
    return 1;
  }

  triat[i] = false;
  int res = f(i + 1, falta);
  triat[i] = true;
  return res + f(i + 1, falta - V[i]);
}


int main() {
  int suma;
  cin >> suma >> n;
  V = triat = VE(n);
  for (int i = 0; i < n; ++i) cin >> V[i];
  cout << f(0, suma) << endl;
}
