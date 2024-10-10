#include <iostream>
using namespace std; 

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    if (x>y and x>z) cout << x << endl;
    if (x>y and x<z) cout << z << endl;
    if (y>x and y>z) cout << y << endl;
    if (y>x and y<z) cout << z << endl;
}
 
