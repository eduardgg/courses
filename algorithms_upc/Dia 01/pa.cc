// Igual que l'anterior, pero cada paraula es pot usar entre 0 i k vegades.


#include <iostream>
#include <vector>
using namespace std;


typedef vector<int> VE;
typedef vector<string> VS;


int n, k;
VS S;
VE V;


void f(int i) {
  if (i == n) {
    for (int j = 0; j < n; ++j)
      for (int r = 0; r < V[j]; ++r) cout << ' ' << S[j];
    cout << endl;
    return;
  }

  for (int j = 0; j <= k; ++j) {
    V[i] = j;
    f(i + 1);
  }
}


int main() {
  cin >> n >> k;
  S = VS(n);
  for (int i = 0; i < n; ++i) cin >> S[i];
  V = VE(n);
  f(0);
}
