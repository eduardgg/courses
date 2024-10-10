#include <iostream>
using namespace std;

int main() {
    char c;
    cin >> c;
    int b = 0;
    while (c != '.') {
        if (c == 'a') b = b + 1;
        cin >> c;
    }
    
    cout << b << endl;
}
 
