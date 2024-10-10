#include <iostream>
using namespace std;

void Hanoi(int n, char from, char to, char aux) {
	if (n > 0) {
		Hanoi(n-1, from, aux, to);
		cout << from << " => " << to << endl;
		Hanoi(n-1, aux, to, from);
	}
}

int main() {
	int Ndisks;
	cin >> Ndisks;
	Hanoi(Ndisks, 'A', 'C', 'B');
}
