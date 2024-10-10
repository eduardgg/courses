#include <iostream>
using namespace std;

int main() {
	char c;
	int acum = 0;
	bool b = true;
	while ((cin >> c) and (b == true)) {
		if (c == ')') --acum;
		if (c == '(') ++acum;
		if (acum < 0) b = false;
	}
	if (b == false) cout << "no" << endl;
	if (b == true and acum == 0) cout << "si" << endl;
	if (b == true and acum != 0) cout << "no" << endl;

}
