// Troba un arbre generador qualsevol d'un graf no dirigit connex donat.


#include <iostream>
#include <vector>
using namespace std;


typedef vector<int> VE;


VE pare;


int repre(int x) {
  if (pare[x] == -1) return x;
  return pare[x] = repre(pare[x]);
}


int main() {
  int n, m;
  while (cin >> n >> m) {
    pare = VE(n, -1);
    while (m--) {
      int x, y;
      cin >> x >> y;
      int rx = repre(x);
      int ry = repre(y);
      if (rx != ry) {
        cout << x << ' ' << y << endl;
        pare[ry] = rx; // no pare[y] = x;
      }
    }
  }
}
