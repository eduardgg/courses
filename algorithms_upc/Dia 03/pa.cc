// Calcula els nombres binomials eficientment, de dalt a baix.
// Versio "professional".


#include <iostream>
#include <vector>
using namespace std;


const int N = 51;


typedef long long ll;
typedef vector<ll> VL;
typedef vector<VL> VVL;


VVL C(N, VL(N, -1));


ll combi(int n, int x) {
  if (x > n or x < 0) return 0;
  ll& res = C[n][x];
  if (res != -1) return res;
  if (x == 0 and n == 0) return res = 1;
  return res = combi(n - 1, x) + combi(n - 1, x - 1);
}


int main() {
  int n, x;
  while (cin >> n >> x) cout << n << ' ' << x << ' ' << combi(n, x) << endl;
}
