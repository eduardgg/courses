#include <iostream>
#include <vector>
using namespace std;

typedef vector <vector <int> > Matriu;

bool es_simetrica (const Matriu& m) {
	int n=m.size();
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) if (m[i][j] != m[j][i]) return false;	
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	Matriu m(n, vector <int> (n));
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) cin >> m[i][j];
	}
	cout << es_simetrica (m) << endl;
}
