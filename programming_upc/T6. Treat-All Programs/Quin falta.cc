#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int n,m;
	while (cin >> n) {
		int suma = (n*(n+1))/2;
		for (int i=1; i<n; ++i) {
			cin >> m;
			suma = suma-m;
		}
		cout << suma << endl;
	}
}
