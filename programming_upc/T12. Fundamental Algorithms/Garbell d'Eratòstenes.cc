#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000;

void marca_multiples (int i, vector<bool>& garbell) {
	for (int j = i*i; j < (int)garbell.size(); j += i) garbell[j] = false;
}

vector<bool> precalcula_garbell(int n) {
	vector<bool> garbell (n, true);
	garbell[0] = garbell[1] = false;
	for (int i = 2; i < MAX; ++i) {
		if (garbell[i]) marca_multiples(i, garbell);
	}
	return garbell;
}

int main () {
	vector<bool> es_primer = precalcula_garbell(MAX*MAX + 1);
	
	int n;
	while (cin >> n) {
		cout << n;
		if (not es_primer[n]) cout << " no";
		cout << " es primer" << endl;
	}
} 
