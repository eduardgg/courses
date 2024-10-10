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

Racional racional (int n, int d) {
	Racional res;
	if (n == 0) {
		res.num = 0;
		res.den = 1;
	}
	else if (n*d > 0) {
		int k = mcd (n, d);
		res.num = n/k;
		res.den = d/k;
	}
	else {
		int k = mcd(n, d);
		res.num = n/k;
		res.den = d/k;
		if (res.den < 0) {
			res.num = -res.num;
			res.den = -res.den;
		}
	}
	return res;
}

int main () {
	int n, d;
	while (cin >> n >> d) {
		Racional res = racional(n, d);
		cout << res.num << '/' << res.den << endl;
	}
} 
