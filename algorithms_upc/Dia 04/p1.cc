// Exemple d'us de push_back i pop_back.
#include <iostream>
#include <vector>
using namespace std;


typedef vector<int> VE;


void escriu(const VE& V) {
    cout << V.size() << endl;
    for (int i = 0; i < (int)V.size(); ++i)
        cout << (i ? " " : "") << V[i];
    cout << endl;
}


int main() {
    VE V;
    int x;
    while (cin >> x) V.push_back(x);
    escriu(V);
    V.pop_back();
    escriu(V);
}
