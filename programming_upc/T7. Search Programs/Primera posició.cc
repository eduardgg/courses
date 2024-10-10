#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int n;
	int a=1;
	int counter=0;
	while ((cin >> n) and (a>0)) {
		++counter;
		if (n%2 == 0) {
			cout << counter << endl;
			--a;
		}
	}
}
