#include <iostream>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		cout << n << " = ";
		
		int u = (n/1)%10;
		int d = (n/10)%10;
		int c = (n/100)%10;
		int m = (n/1000)%10;
		
		//Milers
		if (m == 1) cout << "M";
		if (m == 2) cout << "MM";
		if (m == 3) cout << "MMM";
		
		//Centenes
		if (c == 1) cout << "C";
		if (c == 2) cout << "CC";
		if (c == 3) cout << "CCC";
		if (c == 4) cout << "CD";
		if (c == 5) cout << "D";
		if (c == 6) cout << "DC";
		if (c == 7) cout << "DCC";
		if (c == 8) cout << "DCCC";
		if (c == 9) cout << "CM";
		
		//Desenes
		if (d == 1) cout << "X";
		if (d == 2) cout << "XX";
		if (d == 3) cout << "XXX";
		if (d == 4) cout << "XL";
		if (d == 5) cout << "L";
		if (d == 6) cout << "LX";
		if (d == 7) cout << "LXX";
		if (d == 8) cout << "LXXX";
		if (d == 9) cout << "XC";
		
		//Unitats
		if (u == 1) cout << "I";
		if (u == 2) cout << "II";
		if (u == 3) cout << "III";
		if (u == 4) cout << "IV";
		if (u == 5) cout << "V";
		if (u == 6) cout << "VI";
		if (u == 7) cout << "VII";
		if (u == 8) cout << "VIII";
		if (u == 9) cout << "IX";
		
		cout << endl;
		
	}
}
