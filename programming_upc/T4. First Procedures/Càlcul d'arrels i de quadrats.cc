#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
		int q=n*n;
		cout.setf(ios::fixed);
        cout.precision(6);
        double a=sqrt(n);
        cout << q << " " << a << endl;
	}
}
     
