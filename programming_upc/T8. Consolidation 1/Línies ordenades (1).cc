#include <iostream>
using namespace std;

bool linea_ordenada (int n) {
    bool res = true;
    string s, primer;
    cin >> primer;
    for (int i = 1; i < n; ++i) {
        cin >> s;
        if (s < primer) res = false;
        primer = s;
    }
    return res;
}

int main () {
    int n;
    int j = 1;
    bool existeix = false;
    while (cin >> n and not existeix) {
        if (linea_ordenada(n)) {
            cout << "La primera linia ordenada creixentment es la " << j << '.' << endl;
            existeix = true;
        }
        ++j;
    }
    if (not existeix) cout << "No hi ha cap linia ordenada creixentment." << endl;
} 
