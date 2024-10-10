// Calcula els nombres de Fibonacci eficientment, de baix a dalt.


#include <iostream>
#include <vector>
using namespace std;


const int N = 51;


typedef long long ll;
typedef vector<ll> VL;


VL F(N);


int main() {
  F[0] = 0;
  F[1] = 1;
  for (int i = 2; i < N; ++i) F[i] = F[i-1] + F[i-2];

  int n;
  while (cin >> n) cout << n << ' ' << F[n] << endl;
}
