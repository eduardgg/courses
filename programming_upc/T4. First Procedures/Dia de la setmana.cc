#include <iostream>
using namespace std;

string dia_de_la_setmana(int d, int m, int a) {
	m = m-2;
	if (m <= 0) {
		m = m+12;
		--a;
	}
	int c = a/100;
	int y = a%100;
	int f = d+y-2*c+y/4+c/4+int(2.6*m-0.2);
	int h = f%7;
	
	if (h < 0) h = h+7;
	if (h == 0) return "diumenge";
	if (h == 1) return "dilluns";
	if (h == 2) return "dimarts";
	if (h == 3) return "dimecres";
	if (h == 4) return "dijous";
	if (h == 5) return "divendres";
	if (h == 6) return "dissabte";
} 
