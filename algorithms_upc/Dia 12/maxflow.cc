#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


typedef vector<int> VE;
typedef vector<VE> VVE;


int n;
VVE M;


int flow() {
  queue<int> Q;
  VE pare(n, -1);
  VE flux(n);
  Q.push(0);
  pare[0] = -2;
  flux[0] = 1e9;
  while (not Q.empty()) {
    int x = Q.front(); Q.pop();
    for (int y = 0; y < n; ++y) {
      if (pare[y] == -1 and M[x][y]) {
        Q.push(y);
        pare[y] = x;
        flux[y] = min(flux[x], M[x][y]);

        if (y == n - 1) {
          int f = flux[y];
          while (y != 0) {
            M[x][y] -= f;
            M[y][x] += f;
            y = x;
            x = pare[y];
          }
          return f;
        }
      }
    }
  }
  return 0;
}


int maxflow() {
  int res = 0;
  int f = flow();
  while (f) {
    res += f;
    f = flow();
  }
  return res;
}


int main() {
  int m;
  cin >> n >> m;
  M = VVE(n, VE(n, 0));
  while (m--) {
    int x, y, c;
    cin >> x >> y >> c;
    M[x][y] += c;
  }
  cout << maxflow() << endl;
}
