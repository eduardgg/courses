#include<iostream>
#include<cmath>
#include<string.h>
using namespace std;

int main() {
cout.setf(ios::fixed);
cout.precision(6);//num de decimals
	int a;
    double b,c;
	string e;
	cin >> a;
	
	while(a>=1){
	cin >> e;
	if (e == "rectangle"){
    cin >> b >> c;
    cout << b*c << endl;
    }
    else{
    cin >> b;
    cout << b*b*acos(-1) << endl;
    }
	a--;
}
} 
