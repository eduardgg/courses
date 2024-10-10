#include <iostream>
#include <stack>
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

Racional formalitza(Racional& r) {
	Racional res;
	if (r.num == 0) {
		res.num = 0;
		res.den = 1;
	}
	else if (r.num*r.den > 0) {
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

void llegeix_racional (Racional& r, bool& final) {
	final = false;
	if (cin >> r.num >> r.den) r = formalitza(r);
	else final = true;
}

void escriu_racional(const Racional& r) {
	cout << r.num;
	if (r.den > 1) cout << '/' << r.den;
}

int main () {
	bool finall = false;
	while (not finall) {
		Racional r;
		llegeix_racional(r, finall);
		if (not finall) {
			formalitza(r);
			escriu_racional(r);
			cout << endl;
		}
	}
} 
