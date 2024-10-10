// Troba el cami mes barat per anar des de x fins a la resta de vertexs.
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

const int INF = 1e9;


typedef pair<int, int> P;
typedef vector<int> VE;
typedef vector<P> VP;
typedef vector<VP> VVP;

int n;
VVP G;
VE dist, pare;

void dijkstra(int x) {
      dist = VE(n, INF);
      pare = VE(n, -1);
      priority_queue<P> Q;
      dist[x] = 0;
      pare[x] = -2;
      Q.push(P(0, x));
      int q = 0;
      while (q < n and not Q.empty()) {
            P a = Q.top(); Q.pop();
            int d = -a.first;
            int y = a.second;
            if (d == dist[y]) {
                  ++q;
                  for (int i = 0; i < (int)G[y].size(); ++i) {
                        int z = G[y][i].second;
                        int d2 = d + G[y][i].first;
                        if (d2 < dist[z]) {
                              dist[z] = d2;
                              pare[z] = y;
                              Q.push(P(-d2, z));
                        }
                  }
            }
      }
}

int main() {
      int m;
      while (cin >> n >> m) {
            G = VVP(n);
            while (m--) {
                  int x, y, c;
                  cin >> x >> y >> c;
                  G[x].push_back(P(c, y));
            }
            int x, y;
            cin >> x >> y;
            dijkstra(x);
            if(dist[y] < INF) cout << dist[y] << endl;
            else cout << "no path from " << x << " to " << y << endl;

      }
}
