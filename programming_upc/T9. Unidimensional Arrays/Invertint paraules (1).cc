#include <iostream>
#include <vector>
#include <string>
using namespace std; 

int main() {
	string c;
	while (cin >> c) {
		for (int i=c.size()-1; i>=0; --i) cout << c[i];
		cout << endl;
	 }
 }
