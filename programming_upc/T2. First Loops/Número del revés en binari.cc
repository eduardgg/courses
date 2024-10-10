#include <iostream>
using namespace std;

int main() {
	int d;
	cin >> d;
	if (d==0) cout << d;
	while (d>0) {
		cout << d%2;
		d=d/2;
	 }
	cout << endl;
} 
