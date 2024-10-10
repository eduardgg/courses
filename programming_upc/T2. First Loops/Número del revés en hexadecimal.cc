#include <iostream>
using namespace std;

int main() {
	int d;
	cin >> d;
	int b;
	if (d==0) cout << d;
	while (d>0) {
		b=d%16;
		if (b==10) cout << "A";
		if (b==11) cout << "B";
		if (b==12) cout << "C";
		if (b==13) cout << "D";
		if (b==14) cout << "E";
		if (b==15) cout << "F";
		if (b<10) cout << b;
		d=d/16;
	 }
	cout << endl;
} 
