#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	string first;
	cin >> first;
	string next;
	int length = 1, longest = 1;
	while (cin >> next) {
		if (first != next) length=0;
		else {
			++length;
			if (length > longest) longest = length;
		}
	}
	cout << longest << endl;
}
