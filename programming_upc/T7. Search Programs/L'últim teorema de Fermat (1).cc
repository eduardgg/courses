#include <iostream>
#include <cmath>
using namespace std;

int main () {
    int a, b, c, d;
    while (cin >> a >> b >> c >> d) {
        int res, res2;
        int k, l;
        bool solucio = false;
        for (int i = a; i <= b and not solucio; ++i) {
            for (int j = c; j <= d and not solucio; ++j) {
                res = i*i + j*j;
                res2 = sqrt(res);
                if (res2*res2 == res) {
                    solucio = true;
                    k = i;
                    l = j;
                }
            }
        }
        if (solucio) cout << k << "^2 + " << l << "^2 = " << res2 << "^2" << endl;
        else cout << "Sense solucio!" << endl;
    }
} 
