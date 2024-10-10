// Troba totes les components connexes d'un graf no dirigit,
// fent recorreguts en amplada programats millor.


#include <iostream>
#include <vector>
#include <queue>
using namespace std;


typedef vector<int> VE;
typedef vector<VE> VVE;


VVE G;
VE vist;


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
        queue<int> cua;
        cua.push(x);
        vist[x] = true;
        while (not cua.empty()) {
          int y = cua.front(); cua.pop();
          cout << ' ' << y;
          for (int i = 0; i < (int)G[y].size(); ++i) {
            int z = G[y][i];
            if (not vist[z]) {
              cua.push(z);
              vist[z] = true;
            }
          }
        }
        cout << endl;
      }
	}
}
