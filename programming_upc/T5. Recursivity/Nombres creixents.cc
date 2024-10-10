#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

bool es_creixent (int n){
	if (n<10) return true;
	if(es_creixent(n/10) and ((n/10)%10<= n%10)) return true;
	else return false;
}

int main(){
	int x;
	while (cin >> x) cout << es_creixent(x) << endl;
	}
