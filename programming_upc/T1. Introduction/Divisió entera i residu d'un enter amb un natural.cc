#include <iostream>
using namespace std;
int main () {
    
    int a, b;
    cin >> a >> b;
    int c=a/b;
    int d=a%b;
    if  (d<0) {
        c = c-1;
        d = d+b;
    }
    cout << c << " " << d << endl;
}

