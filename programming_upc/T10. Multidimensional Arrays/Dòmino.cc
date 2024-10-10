#include <iostream>
#include <vector>

using namespace std;

int main(){
	
	int n;
	cin >> n;
	for (int i=0;i<n;++i){
		vector <string> A (10	);
		for (int j=0;j<10;++j){
			cin >> A [j];
		}
		bool perdut=false;
		int j=0;
		while ( j<9 and not perdut){
			int a;
			a=A[j].size() - 1;
			if (A[j][a]!=A[j+1][0]) perdut=true;
			++j;
		}
		if (perdut) {
			if ((j+1)%2==0) cout << "A" << endl;
			else cout << "B" << endl;
		}
		else cout << "=" << endl;
	}
	
} 
