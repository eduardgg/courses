#include <iostream>
using namespace std;

int main() {
	int x;
	cin >> x;
	if (x%4>0) cout << "NO" << endl;
	if (x%400==0) cout << "YES" << endl;
	if (x%4==0 and x%100>0) cout << "YES" << endl;
	if (x%100==0 and x%400>0) cout << "NO" << endl; 
}
