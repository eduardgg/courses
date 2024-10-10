#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int n,m,k,contador=0;
	cin >> n;
	for (int i=1; i<=n; ++i) {
		cin >> k;
		if (k==0) contador = 0;
		else {
			while ((cin >> m) and (m != 0)) {
				if (m>k) ++contador;
				k=m;
			}
		}
		cout << contador << endl;
		contador = 0;
	}
}
			
			

