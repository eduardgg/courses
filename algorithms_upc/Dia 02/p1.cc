// Escriu tots els subconjunts que sumen suma,
// i compta quants n'hi ha.


#include <iostream>
#include <vector>
using namespace std;


typedef vector<int> VE;


int suma, n;
VE V, triat;


int f(int i) {
  if (i == n) {
    int s = 0;
    for (int j = 0; j < n; ++j)
      if (triat[j]) s += V[j];
    if (s != suma) return 0;

    for (int j = 0; j < n; ++j)
      if (triat[j]) cout << ' ' << V[j];
    cout << endl;
    return 1;
  }

  triat[i] = false;
  int res = f(i + 1);
  triat[i] = true;
  return res + f(i + 1);
}


int main() {
  cin >> suma >> n;
  V = triat = VE(n);
  for (int i = 0; i < n; ++i) cin >> V[i];
  cout << f(0) << endl;
}
