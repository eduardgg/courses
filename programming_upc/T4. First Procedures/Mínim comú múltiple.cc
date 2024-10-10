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

int mcm(int a, int b) {
    return (a/mcd(a,b))*b;
}

int main() {
	int a,b;
    while(cin >> a and a!=0){
        int r = 1;
        for(int i = 0; i < a; ++i){
            cin >> b;
            r = mcm(r,b);
        }
        cout << r << endl;
    }
}
