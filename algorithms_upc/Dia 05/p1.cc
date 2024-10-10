#include <iostream>
#include <vector>
using namespace std;


const int MAX = 51;


typedef long long ll;
typedef vector<ll> VL;


VL Z(MAX, -1), U(MAX, -1);


ll u(int n);


ll z(int n) {
    ll& res = Z[n];
    if (res != -1) return res;
    if (n == 1) return res = 1;
    return res = u(n - 1);
}


ll u(int n) {
    ll& res = U[n];
    if (res != -1) return res;
    if (n == 1) return res = 1;
    return res = z(n - 1) + u(n - 1);
}


int main() {
    int n;
    while (cin >> n) cout << z(n) + u(n) << endl;
}
