// Diu si un graf no dirigit es un arbre.


#include <iostream>
#include <vector>
using namespace std;


typedef vector<int> VE;
typedef vector<VE> VVE;


VVE G;
VE vist;


void prof(int x) {
  if (vist[x]) return;
  vist[x] = true;
  for (int i = 0; i < (int)G[x].size(); ++i) prof(G[x][i]);
}


int main() {
  int n, m;
  while (cin >> n >> m) {
    G = VVE(n);
    for (int r = 0; r < m; ++r) {
      int x, y;
      cin >> x >> y;
      G[x].push_back(y);
      G[y].push_back(x);
    }

    int res = 0;
    vist = VE(n, false);
    for (int x = 0; x < n; ++x)
      if (not vist[x]) {
        ++res;
        prof(x);
      }
    cout << (res == 1 and m == n - 1 ? "si" : "no") << " es un arbre" << endl;
	}
}
