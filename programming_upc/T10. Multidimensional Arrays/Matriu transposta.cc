#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>


using namespace std;

typedef vector<vector<int> > Matriu; 

void transposa(Matriu& m){
	int n= m.size();
	int a;
	for (int i = 0; i < n; ++i) {
			for (int j = 0; j < i; ++j){
				a=m[i][j];	
			m[i][j]= m[j][i];
			m[j][i]=a;
		}
	}
}

Matriu read_matrix(int n, int m){
	Matriu v(n, vector<int>(m));
	for (int i=0; i<n; ++i){
		for (int j=0; j<m; ++j){
			cin >> v[i][j];
		}
	}
	return v;
}

int main(){
int n,z;
cin >> n >> z;
Matriu m (n, vector<int>(z));
m = read_matrix(n,z);
transposa(m);
	for (int i=0; i<n; ++i){
		for (int j=0; j<z; ++j){
			cout << m[i][j]<< " ";
		}
		cout << endl;
	}
} 
