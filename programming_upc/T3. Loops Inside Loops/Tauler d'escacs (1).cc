#include <iostream>
using namespace std;
int main(){
	int f,c;
	cin>> f >> c;
	int suma = 0;
	for(int i = 0; i<f; ++i){
		for(int j=0; j<c; ++j){
			char d;
			cin >> d;
			suma = suma + d -'0';
		}
	}
	cout << suma << endl;
}
