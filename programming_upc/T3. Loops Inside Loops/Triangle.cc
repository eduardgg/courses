#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int k=1;
	while (k<=n) {
		int i=1;
		while (i<=k) {
		cout << "*";
		i=i+1;
	}
	cout << endl;
	k=k+1;
}	
} 
