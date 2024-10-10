#include <iostream>
using namespace std;

bool es_perfecte(int n) {
	if (n <= 1) return false;
	int sum = 1;
	int d = 2;
	while (d*d < n) {
		if (n%d == 0) sum = sum+d+n/d;
		d=d+1;
	}
	return n==sum;
} 
