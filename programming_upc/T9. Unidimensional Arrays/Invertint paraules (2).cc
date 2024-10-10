#include <iostream>
#include <vector>
#include <string>
using namespace std; 

int main() {
	int n;
	cin >> n;
	vector <string> v(n);
	for (int i=0; i<n; ++i) cin >> v[i];
	string s;
	for (int i=n-1; i>=0; --i) {
		s = v[i];
		for (int j = s.size() -1; j>=0; --j) cout << s[j];
		cout << endl;
	}
}
