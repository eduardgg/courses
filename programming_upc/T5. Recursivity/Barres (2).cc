#include <iostream>
using namespace std;

void pinta(int n, char c) {
	for (int i=0; i<n; ++i) cout << c;
	cout << endl;
}
	
void barres(int n) {
	if (n == 1) pinta(1,'*');
	else {
		pinta(n,'*');
		barres(n-1);
        barres(n-1);
	}
}

int main() {
	int n;
	cin >> n;
	barres(n);
}
