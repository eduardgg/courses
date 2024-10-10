#include <iostream>
#include <vector>
using namespace std; 

int main() {
	int n;
	while (cin >> n) {
		if (n==0) cout << endl;
		else {
			vector <int> v(n);
			for (int i=0; i<n; ++i) cin >> v[i];
			for (int i=0; i<n-1; ++i) cout << v[n-1-i] << " ";
			cout << v[0] << endl;
		}
	 }
 }
