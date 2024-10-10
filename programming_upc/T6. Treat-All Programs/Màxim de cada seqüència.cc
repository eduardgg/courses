#include <iostream>
using namespace std;

int main() {
	int n;
	
	while (cin >> n) {
	int m=n;
	cin >> n;
	int k=n;
	for(int i=1; i<m; ++i) {
		cin >> n;
		if (n>k) {
			k=n;
		}
	}
cout << k << endl;
}
}
