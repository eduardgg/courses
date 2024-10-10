#include <iostream>
using namespace std;

bool es_any_de_traspas (int any) {
	if (any%4>0) return false;
	if (any%400==0) return true;
	if (any%4==0 and any%100>0) return true;
	if (any%100==0 and any%400>0) return false;
}

int main() {
	int any;
	while (cin >> any) {
		cout << es_any_de_traspas(any) << endl;
	}
}
