#include <iostream>
#include <vector>
using namespace std;

void swap(double& a, double& b) {
	double aux = a;
	a = b;
	b = aux;
}

void insereix(vector<double>& v) {
	int n = v.size() - 1;
	while (n > 0 and v[n-1] > v[n]) {
		swap(v[n-1], v[n]);
		--n;
	}
} 

int main () {
	int n;
	while (cin >> n) {
		vector<double> v (n);
		for (int i = 0; i < n; ++i) cin >> v[i];
		insereix(v);
		for (int i = 0; i < n; ++i) cout << v[i] << ' ';
		cout << endl;
	}
} 
