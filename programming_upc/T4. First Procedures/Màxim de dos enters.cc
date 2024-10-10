#include <iostream>
using namespace std;

int max2(int a, int b) {
	if (a<b) return b;
	if (a>=b) return a;
}

int main() {
	int a,b;
	while (cin >> a >> b) {
		cout << "max2(" << a << ", " << b << ") -> " << max2(a,b) << endl;
	}
}
