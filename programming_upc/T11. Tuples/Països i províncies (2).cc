#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Provincia {
	string nom;
	string capital;
	int habitants;
	int area;
	double pib;
};

struct Pais {
	string nom;
	string capital;
	vector<Provincia> provs;
};

typedef vector<Pais> Paisos;

int habitants(const Paisos& p, double x) {
	int s = 0;
	for (int i = 0; i < p.size(); ++i) {
		int c = 0;
		for (int j = 0; j < p[i].provs.size() and c < 2; ++j) {
			if (p[i].provs[j].pib <= x) ++c;
		}
		if (c >= 2) {
			for (int j = 0; j < p[i].provs.size(); ++j) {
				s += p[i].provs[j].habitants;
			}
		}
	}
	return s;
}

int main () {
	
} 
