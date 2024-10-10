// Exemple d'us de pair.
// Ordena punts en el pla primer per x, i en cas d'empat per y.


#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;


typedef pair<int, int> P;
typedef vector<P> VP;


int main() {
    VP V;
    int x, y;
    while (cin >> x >> y) V.push_back(P(x, y)); // *
    sort(V.begin(), V.end());
    for (int i = 0; i < (int)V.size(); ++i)
        cout << V[i].first << ' ' << V[i].second << endl;
}

/*
    P p;
    p.first = x;
    p.second = y;
    V.push_back(p);
*/
