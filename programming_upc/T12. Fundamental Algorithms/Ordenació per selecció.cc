#include <iostream>
#include <vector>
using namespace std;

int posicio_minim(const vector<double>& v, int esq, int m) {
	int min = esq;
	for (int i = esq + 1; i <= m; ++i) {
		if (v[i] < v[min]) min = i;
	}
	return min;
}

void swap (double& a, double& b) {
	double aux = a;
	a = b;
	b = aux;
}

void ordena_per_seleccio(vector<double>& v, int m) {
	if (m >= 0) {
		for (int i = 0; i < m; ++i) {
			int k = posicio_minim(v, i, m);
			swap(v[i], v[k]);
		}
	}
}

int main () {
	int n;
	while (cin >> n) {
		vector<double> v(n);
		for (int i = 0; i < n; ++i) cin >> v[i];		
		int m;
		cin >> m;
		ordena_per_seleccio(v, m);
		for (int i = 0; i <= m; ++i) cout << v[i] << ' ';
		cout << "--- ";
		for (int i = m + 1; i < n; ++i) cout << v[i] << ' ';
		cout << endl;
	}
} 
