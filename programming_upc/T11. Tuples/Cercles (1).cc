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
	
} 
