#include <iostream>
#include <vector>
using namespace std;

int main () {
	int n;
	while (cin >> n) {
		vector<int> V(n);
		for (int i = 0; i < n; ++i) cin >> V[i];
		int max = 0;
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			sum += V[i];
			if (sum > max) max = sum;
		}
		cout << max << ' ';
		max = 0;
		sum = 0;
		for (int i = n-1; i >= 0; --i) {
			sum += V[i];
			if (sum > max) max = sum;
		}
		cout << max << endl;
	}
} 
