#include <iostream>
#include <vector>

using namespace std;

int main() {
	int a=1000000000;
	int b=1001;
	
	vector <int> ap(b,0);
	int n;
	cin >> n;
	
	for (int i=0; i<n; ++i) {
		int x;
		cin >> x;
		++ap[x-a];
	}
	
	for (int i=0; i<b; ++i) {
		if (ap[i]>0) cout << (a+i) << " : " << ap[i] << endl;
	}
}
