// Troba totes les components connexes d'un graf no dirigit,
// fent recorreguts en profunditat programats iterativament.


#include <iostream>
#include <vector>
#include <stack>
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
        stack<int> pila;
        pila.push(x);
        while (not pila.empty()) {
          int y = pila.top(); pila.pop();
          if (not tractat[y]) {
            tractat[y] = true;
            cout << ' ' << y;
            for (int i = 0; i < (int)G[y].size(); ++i) pila.push(G[y][i]);
          }
        }
        cout << endl;
      }
	}
}
