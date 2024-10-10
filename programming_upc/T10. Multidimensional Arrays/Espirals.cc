#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef vector < string > Matriu;

void r(int a, int& i, int& j, Matriu& M){
	while(a>0){
		M[i][j]='X';
		j++;
		a--;
	}
	j--;
}
	
void u(int a, int& i, int& j, Matriu& M){
	while(a>0){
		M[i][j]='X';
		i--;
		a--;
	}
	i++;
}
	
void l(int a, int& i, int& j, Matriu& M){
	while(a>0){
		M[i][j]='X';
		j--;
		a--;
	}
	j++;
}

void d(int a, int& i, int& j, Matriu& M){
	while(a>0){
		M[i][j]='X';
		i++;
		a--;
	}
	i--;
}



int main(){
	int a, i, j;
	while(cin >> a and a!=0){
		
		Matriu M(a, string(a, '.'));
		
		int nn = M.size();
		j=0;
		i=M.size()-1;
		
		
		//executa
		while(a>0){
		r(a, i, j, M);
		if(j!=nn-1) a--;
		if(a>1) u(a, i, j, M);
		a--;
		if(a>1) l(a, i, j, M);
		a--;
		if(a>1) d(a, i, j, M);
		a--;
		}
		
		
		//imprimeix
		for(int n=0; n < nn; n++) cout << M[n] << endl;
		cout << endl;
	}
} 
