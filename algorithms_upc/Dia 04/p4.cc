// Exemple d'us de map.
// Consulta si una paraula hi es, o l'insereix, o l'esborra.


#include <iostream>
#include <map>
using namespace std;


typedef map<string, int> MSE;
typedef MSE::iterator MI;


int main() {
    MSE M;
    char c;
    string s;
    while (cin >> c >> s) {
        if (c == 'c') {
            MI it = M.find(s);
            if (it == M.end()) cout << s << " no hi es" << endl;
            else cout << it->second << endl;
//            else cout << M[s] << endl;
        }
        else if (c == 'i') ++M[s];
        else {
            MI it = M.find(s);
            if (it == M.end()) cout << "error" << endl;
            else if (--it->second == 0) M.erase(it); // M.erase(s);
        }
    }

    M["patata"] = 23;
}
