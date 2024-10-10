#include <iostream>
using namespace std;

int main() {
	int n,m;
	while (cin >> n) {
		cin >> m;
		int suma = m, max = m;
		for (int i=1; i<n; ++i) {
			cin >> m;
			if (m > max) max=m;
			suma = suma + m;
		}	
		if (suma - max == max) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
