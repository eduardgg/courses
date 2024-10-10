#include <iostream>
using namespace std;

int main() {
    char c;
    int a=0;
    int b=0;
    while (cin >> c) {
        if (c == 'n') b = b - 1;
        if (c == 's') b = b + 1;
        if (c == 'e') a = a + 1;
        if (c == 'o') a = a - 1;
    }
    cout << "(" << a << ", " << b << ")" << endl;
} 
