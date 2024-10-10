#include <iostream>
#include <string>
using namespace std;

int main () {
	string s;
	int res = 0;
	bool beginning = false;
	bool B = false;
	while (cin >> s) {
		if (s == "end") {
			beginning = false;
			break;
		}
		if (beginning) ++res;
		if (s == "beginning") {
			beginning = true;
			B = true;
		}
	}
	if (not beginning and B) cout << res << endl;
	else cout << "wrong sequence" << endl;
} 
