// Troba un arbre generador de cost minim d'un graf no dirigit connex donat
// amb pesos positius a les arestes.


#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;


#define X first
#define Y second


typedef pair<int, int> P;
typedef pair<int, P> PP;
typedef vector<PP> VP;
typedef vector<int> VE;


VE pare;


int repre(int x) {
  return (pare[x] == -1 ? x : pare[x] = repre(pare[x]));
}


int main() {
  int n, m;
  while (cin >> n >> m) {
    pare = VE(n, -1);
    VP V(m);
    for (int i = 0; i < m; ++i) {
      int x, y, c;
      cin >> x >> y >> c;
      V[i] = PP(c, P(x, y));
    }
    sort(V.begin(), V.end());

    for (int i = 0; i < m; ++i) {
      int x = V[i].Y.X;
      int y = V[i].Y.Y;
      int rx = repre(x);
      int ry = repre(y);
      if (rx != ry) {
        cout << x << ' ' << y << ' ' << V[i].X << endl;
        pare[ry] = rx; // no pare[y] = x;
      }
    }
  }
}
