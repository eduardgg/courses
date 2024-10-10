// Troba una ordenacio topologica del graf donat.


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
    VE grau(n, 0);
    while (m--) {
      int x, y;
      cin >> x >> y;
      G[x].push_back(y);
      ++grau[y];
    }

    queue<int> cua;
    for (int x = 0; x < n; ++x)
      if (grau[x] == 0) cua.push(x);

    while (not cua.empty()) {
      int x = cua.front(); cua.pop();
      cout << ' ' << x;
      for (int i = 0; i < (int)G[x].size(); ++i) {
        int y = G[x][i];
        if (--grau[y] == 0) cua.push(y);
      }
    }
    cout << endl;
	}
}
