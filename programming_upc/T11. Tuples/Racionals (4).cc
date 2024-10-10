#include <iostream>
using namespace std;

struct Racional {
	int num, den;
};

int mcd(int a, int b) {
	if (a < b) {
        int aux = a;
        a = b;
        b = aux;
    }
    while (b != 0) {
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int mcm(int a, int b) {
	return (a/mcd(a, b)*b);
}

Racional formalitza(Racional& r) {
	Racional res;
	if (r.num == 0) {
		res.num = 0;
		res.den = 1;
	}
	else if ((r.num < 0 and r.den < 0) or (r.num > 0 and r.den > 0)) {
		int k = mcd (r.num, r.den);
		res.num = r.num/k;
		res.den = r.den/k;
	}
	else {
		int k = mcd(r.num, r.den);
		res.num = r.num/k;
		res.den = r.den/k;
		if (res.den < 0) {
			res.num = -res.num;
			res.den = -res.den;
		}
	}
	return res;
}

Racional suma(const Racional& a, const Racional& b) {
	Racional res;
	res.den = mcm(a.den, b.den);
	int a1 = (res.den/a.den)*a.num;
	int a2 = (res.den/b.den)*b.num;
	res.num = a1 + a2;
	res = formalitza(res);
	return res;
}

Racional resta(const Racional& a, const Racional& b) {
	Racional res;
	res.den = mcm(a.den, b.den);
	int a1 = (res.den/a.den)*a.num;
	int a2 = (res.den/b.den)*b.num;
	res.num = a1 - a2;
	res = formalitza(res);
	return res;
}

Racional producte(const Racional& a, const Racional& b) {
	Racional res;
	res.num = a.num*b.num;
	res.den = a.den*b.den;
	res = formalitza(res);
	return res;
}

Racional divisio(const Racional& a, const Racional& b) {
	Racional res;
	res.num = a.num*b.den;
	res.den = a.den*b.num;
	res = formalitza(res);
	return res;
}

void llegeix_racional (Racional& r) {
	if (cin >> r.num >> r.den) r = formalitza(r);
}

void escriu_racional(const Racional& r) {
	cout << r.num;
	if (r.den > 1) cout << '/' << r.den;
}

int main () {
	Racional r;
	llegeix_racional(r);
	escriu_racional(r);
	cout << endl;
	string pregunta;
	Racional res = r;
	while (cin >> pregunta) {
		Racional s;
		llegeix_racional(s);
		if (pregunta == "suma") res = suma(res, s);
		else if (pregunta == "resta") res = resta(res, s);
		else if (pregunta == "multiplica") res = producte(res, s);
		else res = divisio(res, s);
		escriu_racional(res);
		cout << endl;
	}
} 
