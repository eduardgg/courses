// Diu si un graf no dirigit te algun cicle.


#include <iostream>
#include <vector>
using namespace std;


typedef vector<int> VE;
typedef vector<VE> VVE;


VVE G;
VE vist;


void prof(int x, int& v, int& a) {
  if (vist[x]) return;
  vist[x] = true;
  ++v;
  for (int i = 0; i < (int)G[x].size(); ++i) {
    ++a;
    prof(G[x][i], v, a);
  }
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

    bool cicle = false;
    vist = VE(n, false);
    for (int x = 0; not cicle and x < n; ++x)
      if (not vist[x]) {
        int v = 0;       //v indica el nombre d vertexs d la cc q conte x
        int a = 0;      // a nombre arestes d la cc q conte x
        prof(x, v, a);
        if (v != a/2 + 1) cicle = true;
      }
    cout << (cicle ? "si" : "no") << " te cicle" << endl;
	}
}
