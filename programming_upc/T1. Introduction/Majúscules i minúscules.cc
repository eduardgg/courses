#include <iostream>
using namespace std;

int main(){
    char c;
    cin >> c;
    if (c >= 'A' and c <= 'Z') c = c + ('a' - 'A');
    else c = c + ('A' - 'a');
    cout << c << endl;
}
