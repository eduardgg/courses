#include <iostream>
using namespace std;

int main() {
	cout.setf(ios::fixed);
    cout.precision(10);
	int n, m;
	while (cin >> n >> m) {
	double i=m+1;
	double s=0;
	while (i<=n) {
		s=s+1/i;
		i=i+1;
	}
	cout << s << endl;
}
} 
