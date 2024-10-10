#include <iostream>
using namespace std;

bool es_capicua(int n) {
	int z=n;
	if (n==0) return 1;
	int k=n%10;
	while (n>0) {
		n=n/10;
		if (n!=0) {
			k=k*10+n%10;
		}
	}
	if (k==z) return true;
	if (k!=z) return false;
}

int main() {
	int n;
	while (cin >> n) {
	cout << es_capicua(n) << endl;
}
}
