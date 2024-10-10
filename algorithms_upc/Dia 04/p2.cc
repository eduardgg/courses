// Exemple d'us de map.
// Compta el nombre de vegades que apareix cada paraula.


#include <iostream>
#include <map>
using namespace std;


typedef map<string, int> MSE;
typedef MSE::iterator MI;


int main() {
    MSE M;
    string s;
    while (cin >> s) ++M[s];
    for (MI it = M.begin(); it != M.end(); ++it)
      cout << it->first << ' ' << it->second << endl;
//      cout << (*it).first << ' ' << (*it).second << endl;
}
