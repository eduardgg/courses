#include <iostream>
using namespace std;

int main() {
	int a,b;
	int i=0;
	while (cin >> a >> b) {
i=i+1;
if (a%b != 0) cout << "#" << i << " : " << a+b-a%b << endl;
else cout << "#" << i << " : " << a << endl;
}
} 
