#include <iostream>
using namespace std;

int main() {
	int a;
	cin >> a;
	if (a==0) cout << a;
	while (a>0) {
		cout << (a%10);
		a=a/10;
	}
	cout << endl;
} 
