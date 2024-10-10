#include <iostream>
using namespace std;

int main() {
    int a,b;
    while (cin >> a >> b) {
        if (b==0) cout << "1" << endl;  
        if (a==0 and b!=0) cout << "0" << endl;
        if (a!=0 and b!=0) {
        int i=2;
        int p=a;
        while (i<=b) {
            p=p*a;
            i=i+1;
        }
        cout << p << endl;
    }
    }
} 
