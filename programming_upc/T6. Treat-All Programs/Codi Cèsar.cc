#include <iostream>
using namespace std;

char codificat (char c, int k) {
    if (c == '_') return ' ';
    if (c >= 'a' and c <= 'z') return 'A' + (c - 'a' + k)%26;
    return c;
}

int main () {
    int k;
    while (cin >> k) {
        //recorregut sobre la frase acabada en ".".
        char c;
        cin >> c;
        while (c != '.') {
            cout << codificat(c, k);
            cin >> c;
        }
        cout << endl;
    }         
}
     
