// Troba els camins mes curts i les distancies
// des de 0 fins a tots els altres vertexs.


#include <iostream>
#include <vector>
#include <queue>
using namespace std;


typedef vector<int> VE;
typedef vector<VE> VVE;


int main() {
  int n, m;
  while (cin >> n >> m) {
    VVE G(n);
    while (m--) {
      int x, y;
      cin >> x >> y;
      G[x].push_back(y);
      G[y].push_back(x);
    }

    VE dist(n, -1);
    VE pare(n, -1);
    queue<int> cua;
    cua.push(0);
    dist[0] = 0;
    pare[0] = -2;
    while (not cua.empty()) {
      int y = cua.front(); cua.pop();
      for (int i = 0; i < (int)G[y].size(); ++i) {
        int z = G[y][i];
        if (dist[z] == -1) {
          cua.push(z);
          dist[z] = dist[y] + 1;
          pare[z] = y;
        }
      }
    }

    for (int x = 0; x < n; ++x)
      cout << x << ": " << dist[x] << endl;

    for (int x = 0; x < n; ++x)
      if (pare[x] == -1) cout << "no es pot arribar a " << x << endl;
      else {
        VE V;
        int y = x;
        while (y != 0) {
          V.push_back(y);
          y = pare[y];
        }
        cout << 0;
        for (int i = V.size() - 1; i >= 0; --i)
          cout << ' ' << V[i];
          cout << endl;
      }
	}
}
