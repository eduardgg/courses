#include <iostream>
using namespace std;

int main(){
	int f;
	cin >> f;
	int suma = 0;
	for(int i=1; i<=f; ++i){
		for(int j=1; j<=f; ++j){
			char d;
			cin >> d;
			if ((i==j) or (j+i==f+1)) suma = suma + d -'0';
		}
	}
	cout << suma << endl;
}
 
