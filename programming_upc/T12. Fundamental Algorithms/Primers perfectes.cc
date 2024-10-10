#include <iostream>
using namespace std;

bool primer (int n) {
	if (n == 1) return false; 
	int d = 2;
	while (d*d <= n) {
		if (n%d == 0) return false;
		++d;
	}
	return true;
}

bool primer_perfecte (int n) {
	int sum=0;
	int k=n;
	while (k!=0) {
		sum = sum + k%10;
		k = k/10;
	}
	if (primer (n) == false) return false;
	if ((primer (n) == true) and (n/10 == 0)) return primer(n);
	if ((primer (n) == true) and (n/10 > 0)) return primer_perfecte (sum);
}

int main() {
	int n;
	while ((cin >> n) and (n!=0)) {
		if (primer_perfecte(n) == true) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}
