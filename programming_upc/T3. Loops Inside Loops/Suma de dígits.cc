#include <iostream>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		cout << "La suma dels digits de " << n << " es ";
		int suma = 0;
		while (n !=0) {
			suma = suma + n%10;
			n = n/10;
		}
		cout << suma << "." << endl;
	 }
 }
  
