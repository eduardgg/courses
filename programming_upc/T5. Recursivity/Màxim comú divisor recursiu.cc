#include <iostream> 
#include <cmath> 
#include <cstring> 
using namespace std;

int mcd(int a, int b){
	if (b==0) return a;
	else return mcd(b, a%b);
	}
	
int main() {
	int a,b;
	cin >> a >> b;
	cout << mcd(a,b) << endl;
}
