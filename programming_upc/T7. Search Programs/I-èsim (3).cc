#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int n,m,k;
	cin >> n;
	if (n<=0) cout << "Posicio incorrecta." << endl;
	else {
		for (int i=1; i<n; ++i) cin >> m;
		if (cin >> k) cout << "A la posicio " << n << " hi ha un " << k << "." << endl;
		else cout << "Posicio incorrecta." << endl;
	}
}
