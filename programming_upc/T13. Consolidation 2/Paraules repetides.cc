#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int n;
    while (cin >> n) {
        vector<string> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        sort(V.begin(), V.end());

        vector<int> Q(n + 1, 0);
        int e = 0;
        while (e < n) {
            int d = e + 1;
            while (d < n and V[d] == V[e]) ++d;
            Q[d - e] += V[e].size();
            e = d;
        }

        for (int i = 1; i <= n; ++i) {
            if (Q[i] > 0) cout << i << " : " << Q[i] << endl;
        }
        cout << endl;
    }
} 
