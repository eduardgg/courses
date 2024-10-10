#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	while (cin >> n) {
		if (n==1) {
			int m;
			cin >> m;
			if (m==0) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
		else {
		vector <int> v(n);
		for (int i=0; i<n; ++i) cin >> v[i];
		int suma=0;
		int j=0;
		while (j<n) {
			suma=suma+v[j];
			j=j+1;
		}
		int c=0;
		int i=0;
		while (c==0 and i<n) {
			if (2*v[i]==suma) c++;
			i=i+1; 
		}
		if (c==0) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	
	}
} 
