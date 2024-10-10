#include <iostream>
#include <vector>

using namespace std;


bool hi_es(int x, const vector<int>& v) {
	int n=v.size();
	for (int i=0; i<n; ++i) {
		if (v[i] == x) return true;
	}
	return false;
}

//int main() {
//	int n,x;
//	cin >> n >> x;
//	vector <double> v(n,0);
//	for (int i=0; i<n; ++i) {
//		cin >> v[i];
//	}
//	int a = hi_es(x,v);
//	cout << a;
//}
