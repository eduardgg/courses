
#include <iostream>
using namespace std;

int factorial(int n) {
	int f = 1;
	while (n > 0) {
		f *= n;
		--n;
	}
	return f;
}

int main() {
	int n;
	while (cin >> n) {
		cout << "fact(" << n << ");" << factorial(n) << endl;
	}
}
