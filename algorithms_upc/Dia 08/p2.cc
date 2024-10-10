// Troba totes les components connexes d'un graf no dirigit,
// fent recorreguts en amplada.


#include <iostream>
#include <vector>
#include <queue>
using namespace std;


typedef vector<int> VE;
typedef vector<VE> VVE;


VVE G;
VE tractat;


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

    tractat = VE(n, false);
    for (int x = 0; x < n; ++x)
      if (not tractat[x]) {
        queue<int> cua;
        cua.push(x);
        while (not cua.empty()) {
          int y = cua.front(); cua.pop();
          if (not tractat[y]) {
            tractat[y] = true;
            cout << ' ' << y;
            for (int i = 0; i < (int)G[y].size(); ++i) cua.push(G[y][i]);
          }
        }
        cout << endl;
      }
	}
}
