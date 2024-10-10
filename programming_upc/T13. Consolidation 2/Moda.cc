#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main () {
	int n;
	while (cin >> n and n > 0) {
		vector<string> v(n);
		for (int i = 0; i < n; ++i) cin >> v[i];
		sort(v.begin(), v.end());
		
		string paraula_max = v[0];
		int f = 1;
		int max = 0;
		for (int i = 1; i < n; ++i) {
			if (v[i-1] == v[i]) ++f;
			else {
				if (f >= max) {
					max = f;
					if (i > 0) paraula_max = v[i-1];
					else paraula_max = v[i];
				}
				f = 1;
			}
		}
		if (f >= max) paraula_max = v[n-1];
		cout << paraula_max << endl;
	}
} 
