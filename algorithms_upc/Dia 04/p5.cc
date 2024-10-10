#include <iostream>
// Exemple d'us de set.
// Consulta si una paraula hi es, o l'insereix, o l'esborra.


#include <set>
using namespace std;


typedef set<string> SS;
typedef SS::iterator SI;


int main() {
    SS S;
    char c;
    string s;
    while (cin >> c >> s) {
        if (c == 'c')
            cout << s << (S.find(s) == S.end() ? " no" : "") << " hi es" << endl;
        else if (c == 'i') S.insert(s);
        else S.erase(s);
    }

    for (SI it = S.begin(); it != S.end(); ++it) cout << *it << endl;
}
