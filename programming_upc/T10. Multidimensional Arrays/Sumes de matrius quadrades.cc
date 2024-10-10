#include <iostream>
#include <vector>
using namespace std;

typedef vector <vector <int> > Matriu;
Matriu suma(const Matriu& a, const Matriu& b) {
	int files = a.size();
	Matriu c(files, vector<int>(files));
	for (int i=0; i<files; ++i) {
		for (int j=0; j<files; ++j) {
			c[i][j] = a[i][j] + b[i][j];
		}	
	}
	return c;
}

int main() {
	int n;
	cin >> n;
	Matriu a (n, vector <int> (n)), b (n, vector <int> (n)), c (n, vector <int> (n));
	for (int i = 0; i<n; i++){
		for (int j = 0; j<n; j++) cin >> a[i][j];
	}
	for (int i = 0; i<n; i++){
		for (int j = 0; j<n; j++) cin >> b[i][j];
	}
	c = suma(a, b);
	for (int i = 0; i<n; i++){
		for (int j = 0; j<n; j++) cout << c[i][j];
		cout << endl;
	}
}
