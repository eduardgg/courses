#include <iostream>
#include <string>
#include <vector>

using namespace std; 

struct Persona {
	string nom;
	bool dona;
	int edat;
};

int main(){
	string s;
	int n, em = 0;
	cin >> n;
	vector <Persona> pene (n);
	for ( int i = 0; i < n; ++i){
		cin >> pene[i].nom >> s >> pene[i].edat;
		if (s == "dona") pene[i].dona = true;
		else pene[i].dona = false;
		if (not pene[i].dona) if ( pene[i].edat > em) em = pene[i].edat;
	}
	for (int i = 0; i < n; ++i){
		if (pene[i].dona){
			if (pene[i].edat < em) cout << pene[i].nom << " " << pene[i].edat << endl;
		}
	}
}
