#include <iostream>
using namespace std;

int nombre_digits(int n) {
    int nombre=0;
    if (n==0) return 1;
    while (n != 0) {
        nombre=nombre+1;
        n=n/10;
    }
    return nombre;
} 

int main() {
    int n;
    cin >> n;
    cout << nombre_digits(n) << endl;

}
