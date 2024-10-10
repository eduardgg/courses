#include <iostream>
#include <vector>

using namespace std;


double producte_escalar(const vector<double>& u,const vector<double>& v) {
	double a=0;
	int i=0;
	int n=v.size();
	while (i<n) {
		a=a+v[i]*u[i];
		++i;
	}
	return a;
}

int main() {
	int n;
	cin >> n;
	vector <double> v(n,0);
	vector <double> u(n,0);
	
	for (int i=0; i<n; ++i) {
		cin >> v[i];
	}
	for (int i=0; i<n; ++i) {
		cin >> u[i];
	}
	cout << producte_escalar(u,v) << endl;
}
