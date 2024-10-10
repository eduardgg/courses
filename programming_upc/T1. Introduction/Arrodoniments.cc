#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	double x;
	cin >> x;
	int a=x;
	cout << a << " ";
	if (a==x) cout << a << " ";
	else cout <<a+1 << " ";
	if ((a+1)>(x +0.5)) cout << a << endl;
	else cout << a+1 << endl;
	
} 
