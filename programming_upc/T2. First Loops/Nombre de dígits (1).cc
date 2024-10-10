#include <iostream>
using namespace std;

int main() {
    int a;
    cin >> a;
    if (a==0) cout << "El nombre de digits de " << a << " es " << "1" << "." << endl;
    if (a>0) {
        int i=1;
        int b=a;
        while (b>=10) {
            b=b/10;
            i=i+1;
        }
        cout << "El nombre de digits de " << a << " es " << i << "." << endl;
} 
}
