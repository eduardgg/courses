#include <iostream>
using namespace std;

void canvi_base(int n, int b) {
	if (n == 0) cout << "0";
	else {
		if (n/b > 0) canvi_base(n/b, b);
		
		char x = '0' + n%b;
		if (x > '9') x = 'A' + (x - '9' -1);
		cout << x;
	}
}

int main() {
	int n;
	while (cin >> n) {
		cout << n << " = ";
		canvi_base(n,2);
		cout << ", ";
		canvi_base(n,8);
		cout << ", ";
		canvi_base(n,16);
		cout << endl;
	}
}





