#include <iostream>
using namespace std;

int mcd(int a, int b) {
    int aux;
    while (0 != b) {
        aux = b;
        b = a%aux;
        a = aux;
    }
    return a;
}


int main() {
	int a,b;
    cin >> a >> b;
    cout << mcd(a, b) << endl;
}
