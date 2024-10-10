#include <iostream>
using namespace std;


// llegeix i avalua una expressio correcta
int expre() {
    char c;
    cin >> c;
    if (c >= '0' and c <= '9') return c - '0';
    int esq = expre();
    int dre = expre();
    if (c == '+') return esq + dre;
    if (c == '-') return esq - dre;
    return esq*dre; // '*'
}


int main() {
    cout << expre() << endl;
} 
