#include <iostream>
using namespace std;

int main () {
	int pos;
	while (cin >> pos) {
		int n; cin >> n;
		int cont = 1;
		bool foundya = false;
		while (n != -1) {
			if (cont == pos) {
				cout << "At the position " << pos << " there is a(n) " << n << '.' << endl;
				++cont;
				foundya = true;
			}
			else {
				++cont;
				cin >> n;
			}
		}
		if (not foundya) cout << "Incorrect position." << endl;
	}
} 
