// Calcula el cami mes llarg en un graf dirigit sense cicles.


#include <iostream>
#include <vector>
using namespace std;


typedef vector<int> VE;
typedef vector<VE> VVE;


VVE G;
VE R;


int f(int x) {
  int& res = R[x];
  if (res != -1) return res;
  int veins = G[x].size();
  if (veins == 0) return res = 0;
  res = 0;
  for (int i = 0; i < veins; ++i)
    res = max(res, 1 + f(G[x][i]));
  return res;
}


int main() {
  int n, m;
  while (cin >> n >> m) {
    G = VVE(n);
    while (m--) {
      int x, y;
      cin >> x >> y;
      G[x].push_back(y);
    }

    R = VE(n, -1);
    int res = 0;
    for (int x = 0; x < n; ++x) res = max(res, f(x));
    cout << res << endl;
	}
}
