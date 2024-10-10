#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.precision(6);
    double n;
    while (cin >> n) {
		n=n*3.14159265358979/180;
		cout << sin(n) << " " << cos(n) << endl;
	}
}
     
