#include <iostream>
#include <vector>

using namespace std;

vector<int> concatenacio(const vector<int>&v1, const vector<int>&v2) {
	int n=v1.size();
	int m=v2.size();
	vector <int> v(n+m);
	for (int i=0; i<=n+m-1; ++i) {
		if (i<n) v[i] = v1[i];
		else v[i] = v2[i-n];
	}
	return v;
}
