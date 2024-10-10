#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i=0; i<n; ++i){
		for (int e=1; e<n-i; ++e) cout << " ";
		for (int a=0; a<2*i+1; ++a) cout << "*";
		cout << endl;
	}
	for (int v=0; v<n-1; ++v) {
		for (int aa=0; aa<v+1; ++aa) cout << " ";
		for (int ee=0; ee<2*(n-2-v)+1; ++ee) cout << "*";
		cout << endl;
	}
} 
