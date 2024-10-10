#include <iostream>
using namespace std;

int suma_digits(int n) {
	if (n < 10) return n;
	else return (suma_digits(n/10) + n%10);
}

int reduccio_digits (int x) {
	int s = suma_digits(x);
	if (s < 10) return s;
	else return reduccio_digits(suma_digits(s));
}

bool es_multiple_3 (int n) {
	if ((reduccio_digits(n) == 3) or (reduccio_digits(n) == 6) or (reduccio_digits(n) == 9)) return true;
	return false;
}

int main () {
	int n;
	cin >> n;
	if (es_multiple_3(n)) cout << "si" << endl;
	else cout << "no" << endl;
} 
