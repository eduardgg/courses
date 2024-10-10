// Escriu tots els subconjunts que es poden formar amb n paraules diferents.


#include <iostream>
#include <vector>
using namespace std;


typedef vector<int> VE;
typedef vector<string> VS;


int n;
VS S;
VE V;


void f(int i) {
  if (i == n) {
    for (int j = 0; j < n; ++j)
      if (V[j]) cout << ' ' << S[j];
    cout << endl;
    return;
  }

  V[i] = false;
  f(i + 1);
  V[i] = true;
  f(i + 1);
}


int main() {
  cin >> n;
  S = VS(n);
  for (int i = 0; i < n; ++i) cin >> S[i];
  V = VE(n);
  f(0);
}
