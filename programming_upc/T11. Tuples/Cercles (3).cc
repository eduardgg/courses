#include <iostream>
#include <cmath>
using namespace std;

struct Punt{
	double x, y;
};

struct Cercle {
	Punt centre;
	double radi;
};

double distancia (const Punt& a, const Punt& b) {
	double z = (a.x - b.x)*(a.x - b.x);
	double t = (a.y - b.y)*(a.y - b.y);
	return sqrt(z+t);
}

void desplaca(Punt& p1, const Punt& p2) {
	p1.x += p2.x;
	p1.y += p2.y;
}

void escala(Cercle& c, double esc) {
	c.radi *= esc;
}

void mou_cercle(Cercle& c, const Punt& p) {
	c.centre.x += p.x;
	c.centre.y += p.y;
}

bool es_interior(const Punt& p, const Cercle& c) {
	return (distancia(c.centre, p) < c.radi);
}

bool c1_interior_c2(const Cercle& c1, const Cercle& c2) {
	Punt p1 = c1.centre;
	Punt p2 = c2.centre;
	if (distancia(p1, p2) + c1.radi < c2.radi) return true;
	else return false;
}

bool intersecten(const Cercle& c1, const Cercle& c2) {
	Punt p1 = c1.centre;
	Punt p2 = c2.centre;
	if (distancia(p1, p2) < c1.radi + c2.radi) return true;
	else return false;
}

int relacio(const Cercle& c1, const Cercle& c2) {
	if (c1_interior_c2(c1, c2)) return 1;
	else if (c1_interior_c2(c2, c1)) return 2;
	else if (intersecten(c1, c2)) return 3;
	else return 0;
}

void imprimeix_relacio(const Cercle& c1, const Cercle& c2) {
	if (relacio(c1, c2) == 1) cout << "el primer cercle es interior al segon" << endl;
	else if (relacio(c1, c2) == 2) cout << "el segon cercle es interior al primer" << endl;
	else if (relacio(c1, c2) == 3) cout << "els cercles intersecten" << endl;
	else cout << "els cercles no intersecten" << endl;
}

int main () {
	Cercle c1, c2;
	cin >> c1.centre.x >> c1.centre.y >> c1.radi;
	cin >> c2.centre.x >> c2.centre.y >> c2.radi;
	imprimeix_relacio(c1, c2);
	int i;
	while (cin >> i) {
		string ordre;
		cin >> ordre;
		if (i == 1) {
			if (ordre == "escala") {
				double esc;
				cin >> esc;
				escala(c1, esc);
			}
			else {
				Punt p;
				cin >> p.x >> p.y;
				mou_cercle(c1, p);
			}
			imprimeix_relacio(c1, c2);
		}
		else {
			if (ordre == "escala") {
				double esc;
				cin >> esc;
				escala(c2, esc);
			}
			else {
				Punt p;
				cin >> p.x >> p.y;
				mou_cercle(c2, p);
			}
			imprimeix_relacio(c1, c2);
		}
	}
} 
