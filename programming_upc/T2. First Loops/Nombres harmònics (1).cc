#include <iostream>
using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.precision(4);
	int n;
	cin >> n;
	
    double i=1;
    double p=0;
	while (i<=n) {
		p = p + double(1/i);
		i = i + 1;
	}
    if (n==0) cout << 0.0000 << endl;
    else cout << p << endl;
} 
