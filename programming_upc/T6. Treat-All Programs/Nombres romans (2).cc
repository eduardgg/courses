#include <iostream>
using namespace std;


int val(char c) {
    if (c == 'I') return 1;
    if (c == 'V') return 5;
    if (c == 'X') return 10;
    if (c == 'L') return 50;
    if (c == 'C') return 100;
    if (c == 'D') return 500;
    return 1000; // 'M'
}


int main() {
    char e;
    while (cin >> e) {
        int res = 0;
        cout << e;
        char d;
        while (cin >> d and d != '.') {
            int ve = val(e);
            int vd = val(d);
            if (ve < vd) res -= ve;
            else res += ve;
            cout << d;
            e = d;
        }
        cout << " = " << res + val(e) << endl;
    }
} 
