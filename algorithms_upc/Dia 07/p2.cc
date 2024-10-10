// Troba totes les components connexes d'un graf no dirigit,
// fent recorreguts en profunditat.


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
  cout << ' ' << x;
  for (int i = 0; i < (int)G[x].size(); ++i) prof(G[x][i]);
}


int main() {
  int n, m;
  while (cin >> n >> m) {
    G = VVE(n);
    while (m--) {
      int x, y;
      cin >> x >> y;
      G[x].push_back(y);
      G[y].push_back(x);
    }

    vist = VE(n, false);
    for (int x = 0; x < n; ++x)
      if (not vist[x]) {
        prof(x);
        cout << endl;
      }
	}
}
