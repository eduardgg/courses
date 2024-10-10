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

void suma_un(Racional& r) {
	r.num += r.den;
	formalitza(r);
}

int main () {
	Racional r, s;
	while (cin >> r.num >> r.den >> s.num >> s.den) {
		Racional t = suma(r, s);
		cout << t.num << '/' << t.den << endl;
		t = resta(r, s);
		cout << t.num << '/' << t.den << endl;
		t = producte(r, s);
		cout << t.num << '/' << t.den << endl;
		t = divisio(r, s);
		cout << t.num << '/' << t.den << endl;
		suma_un(t);
		cout << t.num << '/' << t.den << endl;
	}
} 
