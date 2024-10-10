#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int i=1;
	while (i<=10) {
		int a=n*i;
		cout << n << "*" << i << " = " << a << endl;
		i=i+1;
	}
} 
