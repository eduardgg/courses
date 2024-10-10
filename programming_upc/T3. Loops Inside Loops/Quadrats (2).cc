#include <iostream>
using namespace std;

int main() {
	int n,i,j;
	n=0;
	cin >> n;
	while (n != 0) {
		int k=0;
		for (j=1; j<=n; ++j) {
		for (i=1; i<=n; ++i) {
			cout << k;
			k=(k+1)%10;
		}
		cout << endl;
		
		 }
		 n=0;
		if (cin >> n){
			 cout << endl;
	}
	}
}
