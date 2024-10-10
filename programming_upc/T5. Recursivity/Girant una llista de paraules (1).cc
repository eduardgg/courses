#include <iostream>
#include <string>
using namespace std;

void gira_paraules() {
	string mot;
	if (cin >> mot) {
		gira_paraules();
		cout << mot << endl;
	}
}

int main() {
	gira_paraules();
}
