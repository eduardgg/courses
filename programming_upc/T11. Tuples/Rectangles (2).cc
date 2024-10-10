#include <iostream>
#include <vector>
using namespace std;

struct Rectangle {
	int x_esq, x_dre, y_baix, y_dalt;
};

void llegeix (Rectangle& r) {
	cin >> r.x_esq >> r.x_dre >> r.y_baix >> r.y_dalt;
}

bool intersecten(const Rectangle& r1, const Rectangle& r2) {
	if (r1.x_dre <= r2.x_esq or r1.y_dalt <= r2.y_baix or r2.x_dre <= r1.x_esq or r2.y_dalt <= r1.y_baix) return false;
	else return true;
}

int maxim(int a, int b) {
	if (a >= b) return a;
	else return b;
}

int minim(int a, int b) {
	if (a >= b) return b;
	else return a;
}

Rectangle interseccio (const Rectangle& r1, const Rectangle& r2) {
	Rectangle res;
	if (intersecten(r1, r2)) {
		res.x_esq = maxim(r1.x_esq, r2.x_esq);
		res.x_dre = minim(r1.x_dre, r2.x_dre);
		res.y_baix = maxim(r1.y_baix, r2.y_baix);
		res.y_dalt = minim(r1.y_dalt, r2.y_dalt);
	}
	else {
		res.x_esq = 0;
		res.x_dre = 0;
		res.y_baix = 0;
		res.y_dalt = 0;
	}
	return res;
}

int main() {
	int n;
	while (cin >> n and n > 0) {
		if (n > 1) {
			vector<Rectangle> V (n);
			for (int i = 0; i < n; ++i) llegeix(V[i]);
			Rectangle r = interseccio(V[0], V[1]);
			for (int i = 1; i < n; ++i) r = interseccio(r, V[i]);
			if (r.x_esq != 0 or r.y_baix != 0 or r.x_dre != 0 or r.y_dalt != 0) {
				cout << "punt inferior esquerre = (" << r.x_esq << ", " << r.y_baix << "); punt superior dret = (";
				cout << r.x_dre << ", " << r.y_dalt << ')' << endl;
			}
			else cout << "interseccio buida" << endl;
		}
		else {
			Rectangle r;
			llegeix(r);
			cout << "punt inferior esquerre = (" << r.x_esq << ", " << r.y_baix << "); punt superior dret = (";
			cout << r.x_dre << ", " << r.y_dalt << ')' << endl;
		}
	}
} 
