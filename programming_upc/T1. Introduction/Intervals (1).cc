#include <iostream>
using namespace std;

int main() {
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	if (a>d or b<c) cout << "[]" << endl;
	else if (a<=c and b<=d) cout << "[" << c << "," << b << "]" << endl;
	else if (a<=c and b>d) cout << "[" << c << "," << d << "]" << endl;
	else if (a>c and b<=d) cout << "[" << a << "," << b << "]" << endl;
	else if (a>c and b>d) cout << "[" << a << "," << d << "]" << endl;
}
 
