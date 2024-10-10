#include <iostream>
using namespace std;

int suma_digits (int& n) {
	int m = n;
	int sum = 0;
	while (m > 0) {
		sum += m%10;
		m /= 10;
	}
	return sum;
}

int is_prime (int& n) {
	int m = n;
	if (m < 2) return false;
	else {
		for (int i = 2; i*i <= m; ++i) {
			if (m%i == 0 and i != m) return false; 
		}
		return true;
	}
}

bool is_perfect_prime(int n) {
	if (n < 2 or n == 4 or n == 6 or n == 8 or n == 9 or not is_prime(n)) return false;
	if ((n == 2 or n == 3 or n == 5 or n == 7) and is_prime(n)) return true;
	else return (is_perfect_prime(suma_digits(n)));
}

int main () {
	int n;
	while (cin >> n) cout << is_perfect_prime(n) << endl;
} 
