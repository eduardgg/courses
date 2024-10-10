#include <iostream>
using namespace std;

int main() {
	int n;
	cout.setf(ios::fixed);
	cout.precision(10);
	while (cin >> n) {
		cout << "Amb " << n << " terme(s) s'obte ";
		double suma=0;
		int k=n;
		for (int i=0; i<n; ++i) {
			suma=(suma/k)+1;
			k=k-1;
		}
		cout << suma << "." << endl;
}
} 
