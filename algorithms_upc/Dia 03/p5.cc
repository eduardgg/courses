// Calcula els nombres de Fibonacci eficientment, de dalt a baix.


#include <iostream>
#include <vector>
using namespace std;


const int N = 51;


typedef long long ll;
typedef vector<ll> VL;


VL F(N, -1);


ll f(int n) {
  if (F[n] != -1) return F[n];
  if (n <= 1) {
    F[n] = n;
    return F[n];
  }
  F[n] = f(n - 1)+ f(n - 2);
  return F[n];
}


int main() {
  int n;
  while (cin >> n) cout << n << ' ' << f(n) << endl;
}




 
