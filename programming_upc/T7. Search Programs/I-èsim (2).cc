#include <iostream>
#include <vector>
using namespace std;

int main () {
    vector<int> v (1000000);
    int pos, n;
    cin >> pos;
    bool correctpos = false;
    int i = 1;
    while (cin >> n and n != -1 and not correctpos) {
        v[i] = n;
        if (pos < 0) break;
        else if (i == pos) {
            correctpos = true;
            break;
        }
        else correctpos = false;
        ++i;
    }
    if (correctpos) cout << "At the position " << i << " there is a(n) " << n << "." << endl;
    else cout << "Incorrect position." << endl;
}
