#include <iostream>
using namespace std;

int suma_digits(int x) {
	 int r=0;
	 while (x != 0) {
		 r=r+x%10;
		 x=x/10;
	 }
	 return r;
 }
 
int reduccio_digits(int x) {
	if (x/10 == 0) return x;
	else return reduccio_digits(suma_digits(x));
}

int main() {
	int n;
	while (cin >> n) {
		cout << reduccio_digits(n) << endl;
	}
}
