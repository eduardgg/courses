#include <iostream>
#include <vector>

using namespace std;

typedef vector <vector <int> > Matriu;
int main() {
	int m,n;
	cin >> m >> n;
	Matriu c(m, vector <int> (n));
	for (int i=0; i<m; ++i) {
		for (int j=0; j<n; ++j) cin >> c[i][j];
	}
	string s;
	while (cin >> s) {
		if (s == "fila") {
			int fila;
			cin >> fila;
			cout << "fila " << fila << ":";
			for (int i=0; i<n; ++i) cout << " " << c[fila-1][i];
			cout << endl;
		}
		if (s == "columna") {
			int columna;
			cin >> columna;
			cout << "columna " << columna << ":";
			for (int i=0; i<m; ++i) cout << " " << c[i][columna-1];
			cout << endl;
		}
		if (s == "element") {
			int e1, e2;
			cin >> e1 >> e2;
			cout << "element " << e1 << " " << e2 << ":" << " " << c[e1-1][e2-1];
			cout << endl;
		}
	}
} 
