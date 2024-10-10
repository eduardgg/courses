#include <iostream>
using namespace std;

int main() {
	int n,i,j,p;
	cin >> n;
	for (p=1; p<=n; ++p) {
		int k=0;
	for (j=1; j<=n; ++j) {
	for (i=1; i<=n; ++i) {
		cout << k;
		k=(k+1)%10;
	}
	cout << endl;
	}
	if (p != n) cout << endl;
}
}
 
