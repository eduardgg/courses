#include <iostream>
using namespace std;

int main() {
	cout.setf(ios::fixed);
	cout.precision(4);
	
	double x,n;
	cin >> x;
	double s=0;
	while (cin >> n) {
		s=s*x+n;
	}
	cout << s << endl;
} 
