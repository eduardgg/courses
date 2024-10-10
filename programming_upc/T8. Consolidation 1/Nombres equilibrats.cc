#include <iostream>
using namespace std;

bool es_equilibrat (int n) {
	
	int k=n/10;
	int sum1=0;
	int sum2=0;
	while (n!=0) {
		sum1 = sum1 + n%10;
		n = n/100;
	}
	while (k!=0) {
		sum2 = sum2 + k%10;
		k = k/100;
	}
	if (sum1 == sum2) return true;
	else return false;
	
}

int main() {
	int n;
	while (cin >> n) {
		cout << es_equilibrat (n) << endl;	
	}
}
