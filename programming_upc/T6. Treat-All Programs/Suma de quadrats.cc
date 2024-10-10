#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int i=1;
	int suma=0;
	while (i<=n) {
		suma=suma+i*i;
		i=i+1;
	}
	cout << suma << endl;
}
