#include <iostream>
using namespace std;

int main() {
	cout.setf(ios::fixed);
	cout.precision(4);
	double n;
	cin >> n;
	while (cin >> n) {
		int m=n;
		cin >> n;
		double maxim=n;
		double minim=n;
		double mitjana=n;
	for(int i=1; i<m; ++i) {
		cin >> n;
		if (n>maxim) {
			maxim=n;
		}
		if (n<minim) {
			minim=n;
		}
		mitjana=((mitjana*i)+n)/(i+1);
	}
	cout << minim << " " << maxim << " " << mitjana << endl;
}
}
