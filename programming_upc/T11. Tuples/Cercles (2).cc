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

void desplaca(Cercle& c, const Punt& p) {
	c.centre.x += p.x;
	c.centre.y += p.y;
}

bool es_interior(const Punt& p, const Cercle& c) {
	return (distancia(c.centre, p) < c.radi);
}

int main () {
	Cercle c;
	cin >> c.centre.x >> c.centre.y >> c.radi;
	Punt p;
	cin >> p.x >> p.y;
	bool dins = (es_interior(p, c));
	if (dins) cout << "inicialment a dins" << endl;
	else cout << "inicialment a fora" << endl;
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		Punt q;
		cin >> q.x >> q.y;
		desplaca(p, q);
		if (dins and not es_interior(p, c)) {
			dins = false;
			cout << "al pas " << i << " ha sortit a fora" << endl;
		}
		else if (not dins and es_interior(p, c)) {
			dins = true;
			cout << "al pas " << i << " ha entrat a dins" << endl;
		}
	}
}
 
