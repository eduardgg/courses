#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>


using namespace std;

typedef vector<string> Fila; 
typedef vector<Fila> Matriu;

int nombre_de_paraules(const Matriu& m, char c, int k){
		int res=0;
		for (int i=0; i<(int)m.size(); ++i){
			for (int j=0; j< (int)m[i].size(); ++j){
				if (k<(int)m[i][j].size() and m[i][j][k] == c) ++res;
		}
	}
		return res;
	
}
int main(){
int n;
cin >> n;
Matriu M (n);
for (int i=0; i<n; ++i){
	int m;
	cin >> m;
	M[i]= Fila(m);
	for (int j=0; j<m; j++) cin >> M[i][j];
}
char c;
int k;
cin >> c >> k;
nombre_de_paraules(M, c, k);

} 
