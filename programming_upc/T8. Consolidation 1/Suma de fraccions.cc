#include <iostream>
using namespace std;

int main() {
	cout.setf(ios::fixed);
	cout.precision(4);
	double a,b,k;
	while (cin >> a >> b >> k) {
	double suma=0;
	while (a<=b) {
		suma=suma+(1/a);
		a=a+k;
	}
	cout << suma << endl;
}
} 
