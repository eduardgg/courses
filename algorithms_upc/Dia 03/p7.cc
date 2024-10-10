// Calcula els nombres binomials ineficientment.


#include <iostream>
using namespace std;


const int N = 51;


typedef long long ll;


ll combi(int n, int x) {
  if (x == 0 or x == n) return 1;
  return combi(n - 1, x) + combi(n - 1, x - 1);
}


int main() {
  int n, x;
  while (cin >> n >> x) cout << n << ' ' << x << ' ' << combi(n, x) << endl;
}
