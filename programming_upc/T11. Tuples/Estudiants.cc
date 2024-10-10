#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Estudiant{
	int dni;
	string nom;
	double nota;
	bool repetidor;
};

const double NP = -1;

void informacio(const vector<Estudiant>& es, double& min, double& max, double& mitj) {
	min = 11;
	max = 0;
	double sum = 0;
	int cnt = 0;
	for (int i = 0; i < (int)es.size(); ++i) {
		double x = es[i].nota;
		if (not es[i].repetidor and x != NP) {
			++cnt;
			sum += x;
			if (x < min) min = x;
			if (x > max) max = x;
		}
	}
	if (cnt == 0) min = max = mitj = -1;
	else mitj = sum/cnt;
}

void llegeix_es(Estudiant& est) {
	cin >> est.dni; 
	cin >> est.nom;
	cin >> est.nota;
	cin >> est.repetidor;
}

int main () {
	int n;
	while (cin >> n) {
		vector<Estudiant> es (n);
        for (int i = 0; i < n; ++i) llegeix_es(es[i]);
		double min; 
        if (n > 0) min = es[0].nota;
        else min = -1;
		double max = -1;
		double mitj = 0;
		informacio(es, min, max, mitj);
		cout << min << ' ' << max << ' ' << mitj << endl;
	}
} 
