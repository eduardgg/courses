#include <iostream>
using namespace std;

int main() {
	int n,m;
	cin >> n >> m;
	if (n==m) cout << n << endl;
	if (n<m) {
		int i=m;
	while (i>=n) {
		cout << i << endl;
		i=i-1;
	}
}
	if (n>m) {
		int i=n;
	while (i>=m) {
		cout << i << endl;
		i=i-1;
	}
}
}
 
