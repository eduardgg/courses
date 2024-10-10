#include <iostream>
using namespace std;

int main() {
	int x;
	cin >> x;
	int h = x/3600; //hores
	int m = (x%3600)/60; //minuts
	int s = x%60; //segons
	cout << h << " " << m << " " << s << endl;
	
} 
