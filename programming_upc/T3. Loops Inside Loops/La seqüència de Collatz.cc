#include <iostream>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		int i=0;
		while (n!=1) {
			if (n%2 == 0) {
				n=n/2;
				i=i+1;
			}
			else {
				n=3*n+1;
				i=i+1;
			}
	}
	    cout << i << endl;
}
	
} 
