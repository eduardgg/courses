#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;

struct Provincia{
	string nom;
	string capital;
	int habitants;
	int area;
	double pib;
};

struct Pais{
	string nom;
	string capital;
	vector<Provincia>provs;
};

typedef vector<Pais> Paisos;


double pib(const Paisos& p, char c, double d){
	double s=0;
	for (int i = 0; i < (int)p.size(); i++){
		if (p[i].nom[0] == c)
			for (int j=0; j< (int)p[i].provs.size(); ++j){
				int habs = p[i].provs[j].habitants;
				double area = double(p[i].provs[j].area);
				if (habs/area > d){
					s += p[i].provs[j].pib;
				}
			}
		}
	return s;
	}
