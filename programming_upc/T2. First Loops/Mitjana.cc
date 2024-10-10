#include <iostream>
using namespace std;

int main() {
	double n;
    cout.setf(ios::fixed);
    cout.precision(2);
    int i=0;
    double c=0;
    while (cin >> n) {
		i=i+1;
		c=c+n;
	}
	double r=c/i;
	cout << r << endl;
} 
