#include <iostream>
using namespace std;

int main() {
    int a,b;
    while (cin >> a >> b) {
        int p=1;
        int i=0;
        while (p<=b) {
            p=p*a;
            i=i+1;
        }
        cout << i-1 << endl;
    }
} 
